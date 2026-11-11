#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c, t;
int n, d;
int x[N];
struct qw
{
	int u, dis;
};
queue<qw>q;
int f[N];
bool check(int u, int v)
{
	bool first=1;
	int ans=0, dis=0x3f;
	while(!q.empty()) q.pop();
	q.push({u, 0});
	while(!q.empty())
	{
		qw u=q.front();
		q.pop();
		if(u.dis>dis) continue;
		if(u.u>v) continue;
		if(u.u==v) {
			if(first) 
				first=0, dis=u.dis, ans++;
			else if(u.dis==dis)
				ans++;
			else break;
		}
		int to=min(v, f[u.u]);
		for(int i=u.u+1; i<=to; i++) 
			q.push({i, u.dis+1});
	}
	if(ans==2) return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1; i<=n; i++)
			cin>>x[i];
		for(int i=1; i<=n; i++){
			f[i]=0;
			for(int j=i+1; j<=n; j++)
				if(abs(x[j]-x[i])>d){
					f[i]=j-1;
					break;
				}
			if(!f[i]) f[i]=n;
		}
		int ans=0;
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				if(check(i, j))
					ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
