#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,mask=1ll<<30;
int a[N];
bool vis[N];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        vis[i]=1;
    }
    int ans=0,cnt=0;
    for(int i=29;i>=0;i--)
    {
        cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]&&(a[j]>>i)&1) cnt++;
        }
        if(cnt>=m)
        {
            ans+=1<<i;
            for(int j=1;j<=n;j++) if(!(a[j]>>i&1)) vis[j]=0;
        }
    }
    cout<<ans<<"\n";
    return 0;
}