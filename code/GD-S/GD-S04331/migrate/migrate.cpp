/*
Oct31==Dec25?
freopen neuvillette.in/out r/w stdin/out
crystal subway migrate hub
14:30~18:30
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=2e6+7;
int n;
ll d,x[N];
namespace bruteforce
{
	constexpr int N1=309;
	int cnt[N1][N1],dis[N1][N1];
	inline void update(unsigned int S)
	{
		vector<int> p;
		for(int i=0;i<n;i++)
		{
			if(S&(1u<<i)) p.push_back(i+1);
		}
		if(p.size()<2) return;
		int s=p[0],t=p[(int)p.size()-1],len=p.size();
		for(int i=1;i<(int)p.size();i++)
			if(x[p[i]]-x[p[i-1]]>d) return;
		if(len<dis[s][t])
		{
			dis[s][t]=len;
			cnt[s][t]=1;
		}
		else if(len==dis[s][t]) cnt[s][t]++;
//		cerr<<s<<' '<<t<<' '<<len<<':';
//		for(auto x:p) cerr<<x<<' ';
//		cerr<<'\n';
	}
	inline ll solve()
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cnt[i][j]=0;
				dis[i][j]=1e9;
			}
		}
		ll ans=0;
		for(unsigned int i=1;i<(1u<<n);i++) update(i);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) if(cnt[i][j]==2) ans++;
		return ans;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T;
	cin>>c>>T;
	while(T--) cout<<bruteforce::solve()<<'\n';
	cout.flush();
	return 0;
}
/*
显然只能暴力了 
枚举所有2^n种可能经过的路径，维护dis[x,y]和cnt[x,y] 

我不会写次短路板子

AFO？
这或许是我最后一次打CSP了，也许高三还能打？
希望这一次我的发挥对得起我停的1个月文化课
还有6分钟结束了，我也不知道该干什么了 
*/
