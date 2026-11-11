#include <bits/stdc++.h>
#define int long long
#define rint register int
#define il inline
#define ms memset
using namespace std;
const int inf=2e18;
int c,t;
int n,d;
int a[2000005];
int ans;
int f[2000005];
int g[2000005];
int suml[2000005];
int sumr[2000005];
il void d_clear(){
	for(rint i=1;i<=n;i++){
		for(rint j=0;j<=21;j++){
			f[i]=0;
			g[i]=0;
		}
		suml[i]=0;
		sumr[i]=0;
	}
	ans=0;
	return ;
}
il void init(){
	for(rint i=1;i<=n;i++){
		if(a[i]+d>a[n]){
			f[i]=n;
		}else{
			int l=i,r=n+1;
			while(l+1<r){
				int mid=l+r>>1;
				if(a[mid]<=a[i]+d){
					l=mid;
				}else{
					r=mid;
				}
			}
			f[i]=l;
		}
		if(a[i]-d<a[1]){
			g[i]=1;
		}else{
			int l=0,r=i;
			while(l+1<r){
				int mid=l+r>>1;
				if(a[mid]>=a[i]-d){
					r=mid;
				}else{
					l=mid;
				}
			}
			g[i]=r;
		}
	}
	return ;
}
int dp[5005][5005];
int sum[5005][5005];
il void sol(){
	cin>>n>>d;
	for(rint i=1;i<=n;i++){
		cin>>a[i];
	}	
	init();
//	cout<<"here\n";
//	for(rint i=1;i<=n;i++){
//		cout<<f[i]<<' ';
//	}
//	cout<<'\n';
//	for(rint i=1;i<=n;i++){
//		cout<<g[i]<<' ';
//	}
//	cout<<'\n';
	for(rint i=1;i<=n;i++){
		suml[i]++;
		if(i==f[i]) continue;
		suml[f[i]]+=suml[i];
		if(f[f[i]-1]==f[f[i]]){
			suml[f[f[i]]]-=suml[i];
		}
	}
	for(rint i=n;i>=1;i--){
		sumr[i]++;
		if(i==g[i]) continue;
		sumr[g[i]]+=sumr[i];
		if(g[g[i]+1]==g[g[i]]){
			sumr[g[g[i]]]-=sumr[i];
		}
	}
	for(rint i=1;i<=n;i++){
		int to=f[i];
		if(f[i]-i<=1){
			continue;
		}
		int las=f[i]-1;
		if(g[f[f[i]-1]]==f[i]-1){
			ans+=suml[i]*sumr[f[f[i]-1]];
		}
//		cerr<<i<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
	d_clear();
	return ;
}
signed main(){
//	freopen("migrate4.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			cin>>n>>d;
			for(rint i=1;i<=n;i++){
				cin>>a[i];
			}
			for(rint i=1;i<=n;i++){
				for(rint j=1;j<=n;j++){
					dp[i][j]=inf;
					sum[i][j]=0;
				}
			}
			for(rint i=1;i<=n;i++){
				dp[i][i]=0;
				sum[i][i]=1;
				for(rint j=i;j<=n;j++){
					for(rint k=j+1;k<=n;k++){
						if(a[j]+d<a[k]){
							break;
						}
						if(dp[i][k]==dp[i][j]+1){
							sum[i][k]+=sum[i][j];
						}else if(dp[i][k]>dp[i][j]+1){
							dp[i][k]=dp[i][j]+1;
							sum[i][k]=sum[i][j];
						}
					}
				}
			}
			for(rint i=1;i<=n;i++){
				for(rint j=1;j<=n;j++){
					if(sum[i][j]==2){
						ans++;
					}
//					cout<<sum[i][j]<<' ';
				}
//				cout<<'\n';
			}
			cout<<ans<<'\n';
			d_clear();
		}
		return 0;
	}
	while(t--){
		sol();
	}	
	return 0;
}
