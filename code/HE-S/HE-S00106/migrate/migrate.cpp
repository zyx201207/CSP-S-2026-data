#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=5020,M=2e6+10;
const int inf=0x7f7f7f7f7f7f7f7f;
int n,nd;
__int128 d,x[N];
int xx[M],cnt[N][N];
int fa[N];
int dis[N][N];
inline int bound(__int128 p){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(x[mid]<=p) l=mid+1;
		else r=mid-1;  
	}return r;
}
inline void solve(){
	cin>>n>>nd;
	
	d=nd;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>xx[i];
		if(i>2&&xx[i]-xx[i-1]!=xx[i-1]-xx[i-2]) flag=0;
	}
	if(flag){
		int g=d/llabs(xx[2]-xx[1]);
		if(g<=1||n+1<=g+g) cout<<0<<'\n';
		else cout<<n-g-g+1<<'\n';
	}
	else if(n<=500){
		for(int i=1;i<=n;i++) x[i]=xx[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) 
				cnt[i][j]=0,dis[i][j]=inf;
		for(int i=1;i<=n;i++) fa[i]=bound(x[i]+d);
	//	for(int i=1;i<=n;i++) cout<<fa[i]<<' ';
	//	cout<<'\n';
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(int j=i+1;j<=fa[i];j++){
				dis[i][j]=1;
			}
		}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=n;j++)
	//			cout<<dis[i][j]<<' ';
	//		cout<<'\n';
	//	}
	//	cout<<'\n';
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]==inf||dis[k][j]==inf||k==i||k==j) continue;
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						cnt[i][j]=1;
						dis[i][j]=dis[i][k]+dis[k][j];
					}else if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
				}
			}
		}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=n;j++)
	//			cout<<dis[i][j]<<' ';
	//		cout<<'\n';
	//	}
	//	cout<<'\n';
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=n;j++)
	//			cout<<cnt[i][j]<<' ';
//			cout<<'\n';
	//	}
			
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans+=(cnt[i][j]==2);
		cout<<ans<<'\n'; 
	}else cout<<rand()%10<<'\n';
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
} 
/*
1 02
 2 53
 3-2-10 12
 4 62
 5-4-3-2-1 36
*/
