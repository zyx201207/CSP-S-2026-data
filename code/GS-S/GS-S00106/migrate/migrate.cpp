#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using PLI=pair<ll,int>;
const ll MAXN=2000002;
int c,t;
//vector<PLI>g[MAXN];
//vector<int>ans(MAXN);
void solve(){
	int n;
	cin>>n;
	long long d;
	cin>>d;
	vector<ll>a(n+1);
	cin>>a[1]>>a[2];
	ll diff=a[2]-a[1];
	bool ok_A=true;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=diff)ok_A=false;
	}
	/*if(ok_A){
		int max_area=d/diff;
		int ans=max_area-2;
		cout<<ans<<'\n'; 
	}*/if(true){
		int ans=0;
		for(int i=1;i<=n;i++){
			// Don't maybe i+1=j.Or the shortest way only has 1 kind.
			// If i don't straight arrives j,Must has 2 point can arrive
			for(int j=i+2;j<=n;j++){
				if(a[j]-a[i]<=d){
					continue;
				}else if(j==i+2&&a[j]-a[i]>d){
					continue;
				}else if(a[j]-a[i]>d){
					// can or can't used island 
					int used_island=0;
					int not_used_island=0;
					for(int k=i+1;k<=j;k++){
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
							used_island++;
						}
					}
					if(used_island==2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
