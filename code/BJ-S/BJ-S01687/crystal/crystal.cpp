#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=5e5+5;
int n,m,a[N];
void solve()
{
    cin>>n>>m;
    int i,l=1,r,ans=0,sum=0,cnt=0;
    F(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    F(r,1,n) 
    {
        sum+=cnt*(a[r]-a[r-1]),cnt++;
        while(sum>m) sum-=(a[r]-a[l]),l++,cnt--;
        ans=max(ans,cnt);
    }
    cout<<ans;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--) {solve();}
}