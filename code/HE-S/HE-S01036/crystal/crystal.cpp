#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,l,r,tot,ans,a[N],s[N];
int query(int x,int y)
{
  return s[y]-s[x-1];
}
signed main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1; i<=n; ++i)cin>>a[i];
  sort(a+1,a+n+1);
  for(int i=1; i<=n; ++i)s[i]=s[i-1]+a[i];
  for(int l=1,r=1; r<=n; ++r)
  {
    tot=(r-l+1)*a[r]-query(l,r);
    while(tot>m&&l<r)
    {
      ++l;
      tot=(r-l+1)*a[r]-query(l,r);
    }
    ans=max(ans,r-l+1);
  }
  cout<<ans<<'\n';
  return 0;
}
