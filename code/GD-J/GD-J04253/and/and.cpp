#include <bits/stdc++.h>
#define int long long
#define rk(i,l,r) for(int i = l;i<=r;++i)
#define rp(i,r,l) for(int i = r;i>=l;--i) 
#define pb push_back
using namespace std;
const int N = 2e5+10;
int a[N],n,ans=-1,m;
int box[40];
vector<int> v[40],vv;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	rk(i,1,n)cin>>a[i],vv.pb(a[i]);
	rp(k,30,0)
	{
		for(auto i:vv)
		{
			if((i>>k)&1)box[k]++,v[k].pb(i);
		}
		if(box[k]>=m)vv=v[k];
	}
	for(auto k:vv)
	{
		ans&=k;
	}cout<<ans;
	return 0;
}
