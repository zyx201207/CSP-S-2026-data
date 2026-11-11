#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],nxt[N],b[M],ans[M];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        nxt[i]=b[a[i]];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;)
        {
            if(nxt[j]) j=nxt[j];
            else
            {
                ans[a[j]]++;
                j++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
