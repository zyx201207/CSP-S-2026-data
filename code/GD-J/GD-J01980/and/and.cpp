#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll INF=1e9+7;
int n,m;
ll cnt,cnt2;
ll a[maxn],f[maxn][2];
ll mx(ll n,ll j){
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cnt=max(f[i][j],cnt);
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i][0]=a[i];
//	for(int i=1;i<=n;i++){
//		for(int j=2;(j<=i&&j<=m);j++){
//			f[i][j]=mx(i-1,j-1)&a[i];
//		}
//	}

	int flag =1;
	for(int i=1;i<=n;i++){
		if(i>=m){
			f[i][flag]=mx(i-1,!flag)&a[i];
		}
		flag^=1;
	}
	flag^=1;

//	int flag=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(i>=m){
//				f[i][flag]=max(f[i-1][flag],f[i][!flag]&a[i]);
//			}
//		}
//		flag^=1;	
//	}
//	flag^=1;
	
	ll ans=-INF;
	for(int i=1;i<=n;i++){
		ans=max(f[i][flag],ans);
	}
	cout<<ans<<'\n';
} 
