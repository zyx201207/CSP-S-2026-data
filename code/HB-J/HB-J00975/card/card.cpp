#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int a[1000000];
int b[1000000];
int c[1000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        q.push(c[i]);
    }

    for(int i=1;i<=n;i++)
    {
        int tail=0;
        int x=i-1;
        while(x--)
        {
            q.pop();
        }
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            int flag=0;
            for(int j=1;j<=tail;j++)
            if(a[j]==k)
            {
             flag=1;
            }
            if(flag)
            {
                while(1)
                {
                    if(a[tail]==k)
                    {
                        tail--;
                        break;
                    }
                    else tail--;
                }
            }
            a[++tail]=k;
        }
        for(int j=1;j<=m;j++)
        {
            int flag=0;
            for(int g=1;g<=tail;g++)
            {
                if(a[g]==j)
                    flag=1;
            }
            if(flag)
                b[j]++;
        }
        for(int j=1;j<=n;j++)
        {
            q.push(c[j]);
        }
    }
    for(int i=1;i<=m;i++)
    {

        cout<<b[i]<<" ";
    }
    return 0;
}
