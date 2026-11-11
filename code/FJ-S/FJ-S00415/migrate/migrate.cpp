#include<bits/stdc++.h>
#define int long long
#define mst(a,b) memset(a,b,sizeof(a))
#define endl "\n"
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N];
namespace subtask_1_10{
	int r[5005],f[5005][5005],g[5005][5005];
	inline void solve()
	{
		int ans=0;
		mst(f,0);mst(g,0);
		for(int i=n;i;--i)
		{
			for(int j=i;j<=n;++j)
			if(a[j]<=a[i]+d) r[i]=j;
			else break;
			for(int j=i+1;j<=n;++j) 
			f[i][j]=f[min(r[i],j)][j]+1;
		}
		for(int i=1;i<=n;++i)
		g[i][i]=1;
		for(int len=2;len<=n;++len)
		for(int i=1;i+len-1<=n;++i)
		{
			int j=i+len-1;
			if(j<=r[i]) {
				g[i][j]=1;
				continue;
			}
			g[i][j]=g[r[i]][j];
			if(g[i][j]==3) continue;
			if(r[i]==i+1) {
				ans+=(g[i][j]==2);
				continue;
			}
			int now=r[i]-1;
			while(g[now][j] && now!=i && g[i][j]<=2 && f[now][j]+1==f[i][j]) g[i][j]+=g[now][j],--now;
			if(g[i][j]>=3) g[i][j]=3;
			ans+=(g[i][j]==2);
		}
		cout<<ans<<endl;
	}
}
namespace subtask_11_12{
	int f[N],g[N];
	inline void solve()
	{
		int ans=0;
		for(int i=1;i<=n;++i)
		f[i]=0,g[i]=0;
		int cc=a[2]-a[1];
		int can=d/cc;
		f[1]=0,g[1]=1;
		for(int i=2;i<=n;++i)
		{
			if(i<=can+1) 
			{
				f[i]=1,g[i]=1;
				continue;	
			} 
			f[i]=f[i-can]+1;
			g[i]=g[i-can];
			if(g[i]>=3) continue;
			int now=can;
			while(g[i]<=2 && now!=1 && f[i-now+1]+1==f[i] && g[i-now+1]) g[i]+=g[i-now+1],--now;
			if(g[i]>=3) g[i]=3; 
			ans+=(g[i]==2)*(n-i+1);
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		cin>>a[i];
		if(c<=10) 
		{
			subtask_1_10::solve();
			continue;
		}
		if(c==11 || c==12)
		{
			subtask_11_12::solve();
			continue; 
		}
		subtask_1_10::solve();
	}
	return 0;
}
