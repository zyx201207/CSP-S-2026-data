#include<bits/stdc++.h>
using namespace std;
int a[500005];
int d[300005];
int q[300005];
int w[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int x=1;x<=n;x++)
    {
        memset(d,0,sizeof(d));
        memset(q,0,sizeof(q));
        for(int i=1;i<=n;i++)
        {
            if(d[a[i]]>0)
            {
                for(int j=q[a[i]];j<=i;j++)
                {
                    d[a[j]]=0;
                }
                d[a[i]]=1;
                q[a[i]]=i;
            }
            else if(d[a[i]]==0)
            {
                d[a[i]]=1;
                q[a[i]]=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            w[a[i]]+=d[a[i]];
        }
    }
    for(int i=1;i<=m;i++)
        cout<<w[i]<<endl;
    return 0;
}
