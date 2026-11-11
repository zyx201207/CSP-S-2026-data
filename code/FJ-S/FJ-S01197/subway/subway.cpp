#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
ll c,n,m,d,q,w[500005],x,y;
ll ans = 0;
map<pii,ll> mp;
vector <ll> l[505];
vector <ll> s[500005];
inline ll station(ll li,ll walk);
inline ll line(ll sta,ll walk);
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(ll i = 1,k;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			ll st,time;
			mp[{i,st}] = time;
			l[i].push_back(st);
			s[st].push_back(i);
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> x >> y;
		ans = 0;
		cout << line(x,w[x]) << endl;
	}
	return 0;
}
inline ll line(ll sta,ll walk)
{
	if(sta == y) return (walk+w[y]);
	for(ll v : s[sta])
	{
		if(ans == 0) ans = station(v,mp[{v,sta}]+walk);
		else ans = min(ans, station(v,mp[{v,sta}]+walk));
	}
	return ans;
}
inline ll station(ll li,ll walk)
{
	for(ll v : l[li])
	{
		if(ans == 0) ans = line(v,mp[{li,v}]+walk);
		else ans = min(ans, line(v,mp[{li,v}]+walk));
	}
	return ans;
}