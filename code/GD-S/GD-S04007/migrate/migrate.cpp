#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
map<pair<int,int>,int>mp;
void solve1(){
	int T;cin >> T;
	while(T--){
		int n,d;cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> a[i];
		for(int k=0;k<(1<<n);k++){
			bool f=0;
			for(int i=1;i<=n;i++){
				if(!k&(1<<(i-1)))continue;
				for(int j=i;j<=n;j++){
					if(!k&(1<<(j-1)))continue;
					if(a[j]-a[i]>k)f=1;
					break;
				}
			}
			if(f)continue;
			for(int i=1;i<=n;i++){
				if(!k&(1<<(i-1)))continue;
				for(int j=i;j<=n;j++){
					if(!k&(1<<(j-1)))continue;
					if(i==j)continue;
					mp[{i,j}]++;
					break;
				}
			}
		}
		int ans=0; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(mp.count({i,j}))ans=max(ans,mp[{i,j}]);
			}
		}
		//cout << ans << "\n";
	}
}
void solve2(){
	int T;cin >> T;
	while(T--){
		int n,d;cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> a[i];
		int m=a[2]-a[1];
		if(d/m<=1){cout << 0 << "\n";continue;}
		cout << max(n-d/m-1,0ll) << "\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;cin >> c;
	solve2(); 
}
