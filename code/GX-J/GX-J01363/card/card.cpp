#include<bits/stdc++.h>
using namespace std;
int a[500001],t[100001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,f,v=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(v<=n)
    {
        for(int i=1;i<=n;i++)
            t[i]=-1;
        for(int i=v;i<=n;i++)
        {
            t[i]=a[i];
            for(int j=1;j<i;j++)
            {
                if(t[j]==-1)
                    continue;
                if(t[j]==a[i])
                {
                    for(int x=j;x<i;x++)
                        t[x]=-1;
                    break;
                }
            }
        }
        f=0;
        for(int j=1;j<=n;j++)
        {

            if(t[j]==-1)
                continue;
            if(t[j]==v)
            {
                cout<<v<<' ';
                break;
            }
        }
        v++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
