#include<bits/stdc++.h>
using namespace std;
namespace MoonHalfx{
	#define int long long
//	#define f(x,y) dp[x][y] 
	const int N=2e6+5;
	int n,m;
	int a[N];
	int f[N],g[N];//到达i的最少次数，路线数量(1/2/3)
	int lst[N];
//	int dp[N][4];
	inline void solve(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			lst[i]=-1;
			int lef=1,rig=i-1;
			while(lef<=rig){
				int mid=(lef+rig)>>1;
				if(a[mid]+m>=a[i])rig=mid-1,lst[i]=mid;
				else lef=mid+1;	
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=1,g[i]=0;
			for(int j=i+1;j<=n;j++){
				if(lst[j]==-1)break;
				int cd=max(lst[j],i);
				f[j]=0;
				for(int ij=cd;ij<=min(cd+2,j-1) && g[ij]==g[cd];ij++)f[j]+=f[ij];
				g[j]=g[cd]+1,f[j]=min(f[j],3ll);
				if(f[j]==2)ans++;
			}
		} 
		cout<<ans<<"\n";
//		for(int i=1;i<=n;i++)f(i,1)=1,f(1,2)=f(1,3)=0;
//		for(int i=1;i<=n;i++){
//			if(lst[i]==-1)continue;
//			int lt=lst[i],lt1=min(lst[i]+1,i-1),lt2=min(lst[i]+2,i-1);
//			f(i,1)=f(lt,1);
//			f(i,2)=f(lt1,1)-f(lt,0); 
//		}
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			ans+=f(i,2);
//			cout<<i<<" "<<f(i,2)<<"\n";
//		}
//		cout<<ans<<"\n";
		return;
	}
	signed main(){
		int c,T;
		cin>>c>>T;
		while(T--)solve(); 
		return 0;
	}
	#undef int
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	MoonHalfx::main();
	return 0;
}
/*
f(i 0)=f(cd 0)
f(i 1)=f(cd+1 0) - f(cd 0) - f(cd 2) 
f(i 2)=f(cd+1 0) - f(cd 0) - f(cd 1)
	  +f(cd+2 0) - f(cd+1 2) - f(cd+1 1) + f(cd 1) - f(cd+1 0) + f(cd 2)
*/
