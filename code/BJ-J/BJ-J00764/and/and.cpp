#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N];
long long ans;
bool vis[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    fill(vis+1,vis+n+1,true);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=29;i>=0;i--)
    {
        int c=0;
        for(int j=1;j<=n;j++) if(vis[j]&&(a[j]>>i&1)) c++;
        if(c<m) continue;
        for(int j=1;j<=n;j++) if((a[j]>>i&1)==0) vis[j]=false;
        ans+=(1ll<<i);
    }
    cout<<ans;
    return 0;
}
