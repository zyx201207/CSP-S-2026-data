#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        bool s[500005],v[300005];
        int k[300005];        
        memset(v,0,sizeof(v));
        memset(s,0,sizeof(s));
        memset(k,0,sizeof(k));
        for(int j=i;j<=n;j++)
        {
            if (v[a[j]])
            {
                for(int r=k[a[j]];r<j;r++)
                {
                    s[r]=0;
                }  
            }
            v[a[j]]=1;
            s[j]=1;
            k[a[j]]=j;
        }
        for(int j=i;j<=n;j++)
        {
            if (s[j])
            {
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}