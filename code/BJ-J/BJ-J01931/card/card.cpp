#include<bits/stdc++.h>
using namespace std;
int a[300005];
int b[300005];
queue<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            bool f=1;
            int w=q.size();
            for(int k=1;k<=w;k++)
            {
                int t=q.front();
                q.pop();
                if(t!=a[j]&&f==1)q.push(t);
                else f=0;
            }
            q.push(a[j]);
        }
        while(!q.empty())
        {
            b[q.front()]++;
            //cout<<q.front()<<" ";
            q.pop();
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
