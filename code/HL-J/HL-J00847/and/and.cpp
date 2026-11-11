#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 2e5+10 ;
ll a[maxn],n,m,f[maxn][32] ;
bool vis[32],flag[maxn] ;
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0) ;
	cin>>n>>m ;
	int highest=-1 ;
	for(int i=1;i<=n;i++){
		cin>>a[i] ;
		for(int j=30;j>=0;j--){
			if(a[i]>=(1<<j)){
				f[i][j]=1 ;
				a[i]-=(1<<j) ;
				highest=max(highest,j) ;
			}
		}
	}
	for(int i=0;i<=n;i++){
		flag[i]=1 ;
	}
	bool is_counted=0 ;
	for(int i=highest;i>=0;i--){
		int cnt=0 ;
		for(int j=1;j<=n;j++){
			if(f[j][i]==1&&flag[j]==1){
				cnt++ ;
				if(is_counted){
					flag[j]=1 ;
				}
			}
			else if(f[j][i]==0&&is_counted){
				flag[j]=0 ;
			}
		}
		if(cnt>=m){
			vis[i]=1 ;
			is_counted=1 ;
		}
	}
	ll ans=0 ;
	for(int i=30;i>=0;i--){
		if(vis[i]){
			ans+=(1<<i) ;
		}
	}
	cout<<ans ;
	return 0 ;
}
