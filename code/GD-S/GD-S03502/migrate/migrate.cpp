#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2082000, smallN = 333;
const ll inf = 1152921504606846976;
ll n, m,i,j,k,c,T,d,x[N],u,v,minx,tmp, ww,ans,flag,rd;
void dfs(ll u, ll v, ll kkk)
{
//	cout << u << endl;
	if (rd > 2LL) return;
	if (kkk == minx)
	{
		if (u == v) rd ++;
		return;
	}
	ll vv = u+1LL;
	while (1LL)
	{
		if (x[vv] - x[u] > d) break;
		dfs(vv, v, kkk+1);
		vv++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		ans = 0;
		for (i=1; i<=n; i++)
		{
			cin >> x[i];
		}
		for (u=1; u<n; ++u)
		{
			for (v=u+1LL; v<=n; v++)
			{
//				cout << v << endl;
				if (abs(x[u] - x[v]) <= d) continue;
				tmp = x[u];
				ww = u;
				minx = 0;
				flag = 1;
				while (ww < v)
				{
//					cout << ww << endl;
					if (flag == 0)
					{
						minx = -inf;
						break;
					 } 
					flag = 0;
					while (abs(tmp - x[ww+1]) <= d && ww != v) ww++, flag = 1;
					tmp = x[ww];
					minx ++;
				}
//				cout << u << " " << v << " " << minx << endl;
				rd = 0;
				dfs(u,v,0);
				if (rd == 2)ans++;
//				else break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

