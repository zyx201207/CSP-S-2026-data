#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6;
//×î¶ÌÂ·
ll c,t,n,d,x[maxn];
ll f[5005][5005];
bool vis[5005][5005];
ll ans[5005][5005];
void solve(){
	for(int i=1;i<=n;i++){//Çå¿Õ 
		for(int j=1;j<=n;j++){
			ans[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll sum=abs(x[i]-x[j]);
			if(sum<=d){
				ans[i][j]=j-i-1;
				vis[i][j]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			for(int k=i+1;k<j;k++){
				if(vis[i][k]&&vis[k][j]&&!vis[i][j]){
					ans[i][j]++;
				}
			}
		}
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans[i][j]==2){
				sum++;
			}
		}
	}
	cout<<sum<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		solve();
	}
	return 0;
}
