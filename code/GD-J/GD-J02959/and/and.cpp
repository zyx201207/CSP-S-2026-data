#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+9;
ll a[N];
ll sum[N];
ll f[100][100];
void solved(){
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]&a[i];
	ll ans=0;
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return ;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return ;
	}
	if(m==n){
		cout<<sum[n];
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=max(f[i][j],f[i-1][j]&(sum[j]&sum[j-i+1]));
		}
	}
	cout<<f[n][m];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cout<<fixed<<setprecision(1);
//	int t; cin>>t; while(t--)
	solved();
	return 0;
}


