#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
int d[300010];
int f[300010];
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
        int cur=0;
        for(int j=i;j<=n;j++)
        {
            if(f[a[j]]==0)
            {
                d[++cur]=a[j];
                f[a[j]]=1;
            }
            else
            {
                while(d[cur]!=a[j])
                {
                    f[d[cur]]=0;
                    d[cur]=0;

                    cur--;
                }
            }
        }
        for(int i=1;i<=cur;i++)
        {
            ans[d[i]]++;
        }
        memset(f,0,sizeof f);
        memset(d,0,sizeof d);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
