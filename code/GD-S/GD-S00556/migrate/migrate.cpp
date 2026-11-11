#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int C,T,n,d,x[N],dis[N],cnt[N],ans;
void solve_task1()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		fill(dis,dis+n+1,0x3f3f3f3f3f3f3f3f);
		fill(cnt,cnt+n+1,0);
		dis[i]=0,cnt[i]=1;
		for(int j=i+1;j<=n;j++)
		{
			int lim=-1;
			for(int k=j-1;k>=i;k--)
			{
				if(x[j]-x[k]>d) 
				{
					lim=k+1;
					break;
				}
			}
//			cout<<lim<<' ';
			if(lim==-1) lim=i;
			if(lim==j) continue;
			int minn=0x3f3f3f3f3f3f3f3f,sum=0;
			for(int k=lim;k<j;k++) 
			{
				minn=min(minn,dis[k]);
			}
			for(int k=lim;k<j;k++)
			{
				if(dis[k]==minn) sum+=cnt[k];
			}
			dis[j]=minn+1;
			cnt[j]=sum;
			if(cnt[j]==2&&dis[j]<0x3f3f3f3f3f3f3f3f) ans++;
		}
//		cout<<'\n';
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) solve_task1();
	return 0;
} 
