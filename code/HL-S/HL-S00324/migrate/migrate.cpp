#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6 + 10;
int c,T,n,d,a[maxn];
bool vis[maxn];int cnt1 = 0,mi1 = 1e18;
void dfs(int l,int r,int dep)
{
	if(dep == r)
	{
		int lst = a[l],len = 2;
		for(int i = l+1;i <= r-1;i++)
		{
			if(!vis[i]) continue;
			if(vis[i]) len++;
//			cout << "a[i]-st :" << a[i] << " " << lst << endl;
			if(a[i]-lst > d) return;
			lst = a[i];
		}
//		cout << "L R: "<< l << " " << r << endl << "Vis: ";
//		for(int i = l+1;i <= r-1;i++)
//			cout << vis[i] << " ";
//		cout << endl;
		if(a[r]-lst <= d) 
		{
			if(len < mi1) cnt1 = 0,mi1 = len;
			if(len == mi1) cnt1++;
		}
//		cout << "cnt1:" << cnt1 << endl;
		return;
	}
	vis[dep] = 1;
	dfs(l,r,dep+1);
	vis[dep] = 0;
	dfs(l,r,dep+1);
	return; 
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		int ans1 = 0;
		for(int l = 1;l <= n;l++)
			for(int r = l+1;r <= n;r++)
			{
				cnt1 = 0; mi1 = 1e18;
				dfs(l,r,l+1);
				if(cnt1 == 2) ans1++;
			}
		cout << ans1 << "\n";
	}
	return 0;
}

