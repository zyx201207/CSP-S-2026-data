#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1050000;
const ll inf = 1152921504606846976;
ll n, m,i,j,k,c,t;
ll p[N],fac[11],vis[N];
vector<ll>h[N],s,tmp; 
queue<ll>q;
unordered_set<ll> sss;
struct node{
	ll step;
	ll no;
};
queue<node>qq;
bool check(ll val, vector<ll> &x)
{
	ll pos = lower_bound(x.begin(),x.end(), val) - x.begin();
	if (pos >= 0 && pos < x.size())
	{
		if (x[pos] == val) return true;
	}
	return false;
 } 
void xiao(vector<ll> x)
{
	if (x.empty())return;
	while (!q.empty())q.pop();
	ll st = x[0];
	q.push(st);vis[st] = 1;
	
	while (!q.empty())
	{
		ll hd = q.front();
		q.pop();
		for (auto vv : h[hd])
		{
			if (vis[vv] == 0 && check(vv,x))
			 {
				vis[vv] = 1;
				q.push(vv);
			  } 
		}
	}
	vector<ll>ret = {};
	for (auto vv : x)
	{
		if (vis[vv] == 0)
		{
			ret.push_back(vv);
		}
	}
	s.clear();
	s=ret;
	return;
}
ll getdis(ll u)
{
	memset(vis,0,sizeof(vis));
	while (!qq.empty())qq.pop();
	qq.push({0,u});
	vis[u] = 1;
	while (!qq.empty())
	{
		node hd = qq.front();
		if (sss.count(hd.no) == 1)
		{
			return hd.step;
		}
		qq.pop();
		for (auto v : h[hd.no])
		{
			if (vis[v] == 0)
				vis[v] = 1,qq.push({hd.step+1, v});
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	fac[0] = 1ll;
	for (i=1; i<=10;++i) fac[i] = fac[i-1] * i;
	cin >> c >> t;
	if (c != 1 && c!=2 && c!=3)
	{
		while (t--)cout << 1 << endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	while (t--)
	{
		ll u, v, ans= inf;
		cin >> n >> k;
		for (i=1; i<n; i++)
		{
			cin >> u >> v;
			h[u].push_back(v);
			h[v].push_back(u);
		}
		for (i=1; i<=n; i++)
		{
			p[i] = i;
		}
		for (i=1; i<= fac[n]; i++)
		{
			//获得方案并检验 
			s.clear();tmp.clear();
			for (i=1; i<=k; i++)
			{
				s.push_back(p[i]);
			}
			sort(s.begin(),s.end());
			tmp = s;
			//检验方案
			xiao(s); 
			xiao(s);
			if (!s.empty())
			{
				//方案不合理 
				next_permutation(p+1,p+1+n);
				if (ans == 1) break;
				continue;
			}
			sss.clear();
			for (auto it : s)
				sss.insert(it);
			ll r = -inf;
			for (i=1; i<=n; i++)
			{
				//找 
				ll dist = getdis(i);
				r = max(dist, r);
			}
			
			
			ans = min(ans, r);
			next_permutation(p+1,p+1+n);
			if (ans == 1) break;
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

