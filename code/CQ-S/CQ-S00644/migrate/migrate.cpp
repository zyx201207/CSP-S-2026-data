#include <bits/stdc++.h>
#define int long long 
using namespace std;
bool st;
const int N = 2e6+5;
int n,d,a[N],tr[N],tl[N],sr[N],sl[N];
vector<int> vec1[N],vec2[N];
bool en;
inline void solve()
{
	cin>>n>>d;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	for(int i = 1;i<=n+1;i++) vec1[i].clear(),vec2[i].clear();
	for(int i = 1;i<=n;i++)
	{
		tr[i] = lower_bound(a+1,a+n+1,a[i]+d+1)-a-1;
		tl[i] = lower_bound(a+1,a+n+1,a[i]-d)-a;
		if(tl[i]!=i) vec1[tl[i]].push_back(i);
		if(tr[i]!=i) vec2[tr[i]].push_back(i);
	}
	tl[n+1] = 0,tr[n+1] = n+1;
	for(int i = 1;i<=n;i++)
	{
		if(tl[i]!=i&&tr[tl[i]]==i) sl[i] = sl[tl[i]]+1;
		else sl[i] = 0;
		for(auto x:vec2[i]) if(x>tl[i]) sl[i]++;
	}
	for(int i = n;i;i--)
	{
		if(tr[i]!=i&&tl[tr[i]]==i) sr[i] = sr[tr[i]]+1;
		else sr[i] = 0;
		for(auto x:vec1[i]) if(x<tr[i]) sr[i]++;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		if(tr[i]==i||tr[tr[i]]==tr[i]) continue;
		int p = tr[tr[i]];
		if(tl[tl[p]]==i&&tr[i]==tl[p]+1)
		{
//			cout<<"xx"<<i<<' '<<p<<":"<<sl[i]<<' '<<sr[p]<<'\n';
			ans+=sl[i]*sr[p];
		}
	}
	for(int i = 1;i<=n;i++)//i 作起点
	{
		if(tr[i]==i||tr[tr[i]]==tr[i]) continue;
		int p = tr[tr[i]];
		if(tl[tl[p]]<=i&&tr[i]==tl[p]+1)
		{
//			cout<<"st"<<i<<" "<<p<<":"<<sr[p]<<'\n';
			ans+=sr[p];
		}
	}
	for(int i = 1;i<=n;i++)//i 作终点
	{
		if(tl[i]==i||tl[tl[i]]==tl[i]) continue;
		int p = tl[tl[i]];
		if(tr[tr[p]]>=i&&tr[p]==tl[i]+1)
		{
//			cout<<"ed"<<i<<" "<<p<<":"<<sl[p]<<'\n';
			ans+=sl[p];
		}
	}
	for(int i = 1;i<n;i++)
	{
		int cl = 0,cr = 0;
		if(tl[i]==i||tl[i]<1) continue;
		if(tr[i+1]==i+1||tr[i]>n) continue;
		for(auto x:vec2[i+1]) if(x>=tl[i]&&x<i) cl++;
		for(auto x:vec1[i]) if(x<=tr[i+1]&&x>i+1) cr++;
//		cout<<"xx"<<i<<' '<<i+1<<":"<<cl<<"*"<<cr<<'\n';
		ans+=cl*cr;
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cerr<<(&st-&en)/1024/1024<<"MB\n";
	int cid,T;cin>>cid>>T;
	while(T--) solve();
	return 0;
}

