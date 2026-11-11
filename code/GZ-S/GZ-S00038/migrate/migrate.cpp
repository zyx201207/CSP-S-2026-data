//GZ-S00038 贵阳市白云区华师一学校 林乾翔 
//做一个最短路，然后记一下数 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,INF=1e18;
int c,t,n,d,x[N],dis[N][N],cnt[N][N]; 
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=INF,cnt[i][j]=0;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		init(n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(abs(x[i]-x[j])<=d) 
				{
					dis[i][j]=dis[j][i]=1,cnt[i][j]=cnt[j][i]=1;
//					cout<<i<<' '<<j<<'\n';
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++) 
				{
					if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++) 
			{
//				cout<<cnt[i][j]<<' ';
				if(cnt[i][j]==2) ans++;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//CSP-S 2026 rp++
//管理好时间
//记得打暴力
//今年能一等！！！
//相信自己。
//注意溢出和边界问题
//先把分拿完，然后手造样例过
//相信数据强度
//写对拍 
//期望得分: 100+48+24=172,不要挂分啊qwqpwp  
