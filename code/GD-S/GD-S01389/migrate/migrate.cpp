#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(0)
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N=2e6+5;
int T,n,m,ans,Taskid;
int a[N];
int dis[N];
int cnt[N];
double st,ed;
void solve()
{
	cin>>n>>m,ans=0;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n)
	{
		cnt[i]=1,dis[i]=0,cnt[i-1]=0;
		// cerr<<"0 ";
		rep(j,i+1,n)
		{
			cnt[j]=0;
			int p=lower_bound(a+i,a+j+1,a[j]-m)-a;
            if(p==j) dis[j]=LLONG_MAX/3;
            else dis[j]=dis[p]+1;
			// cerr<<dis[j]<<' ';
		}
		int r=i+1,l=i+1,fl=0;
		rep(j,i,n)
		{
			if(dis[j]==dis[j-1]) cnt[j]+=cnt[j-1];
			// if(cnt[j]==2) cerr<<i<<" "<<j<<'\n';
			ans+=(cnt[j]==2),fl=0;
			int tr=r;
			while(r<=n&&dis[r]!=dis[j]+1) r++;
			if(tr!=r) l=r;
			if(r==n+1) continue;
			while(r<n&&a[r+1]-a[j]<=m) r++;
			if(a[r]-a[j]<=m)
			{
				cnt[l]+=cnt[j],fl=1;
				if(dis[r+1]==dis[r]) cnt[r+1]-=cnt[j];
			}
		//   end:
			// cerr<<"cnt = "<<cnt[j]<<"  l = "<<l<<"   ";
			// cerr<<j<<" : "<<l<<" "<<r<<" "<<fl<<'\n';
		}
		// cerr<<'\n';
	}
	// cerr<<'\n';
	// cerr<<ans<<"\n";
	cout<<ans<<'\n';
}
signed main()
{
	// st=clock();
	// fre(migrate);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Tie,cin>>Taskid>>T;
	while(T--) solve();
	// ed=clock();
	// cerr<<(ed-st)*1.0/CLOCKS_PER_SEC;
	return 0;
}//40pts