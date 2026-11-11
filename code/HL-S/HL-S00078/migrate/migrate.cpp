#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =1e3 + 5;
int c,t,n,d;
int mxt,mnt;
int x[N];
int mxans = 1e18;
int cnt;
void dfs(int nw,int gl,int ct){
	
	if(ct > mxans)return;
	if(nw == gl){
		if(ct == mxans)cnt++;
		else if(ct <mxans){
			cnt=1;
			mxans = ct;
		}
		return;
	}
	for(int i = nw + 1;i <= gl;i++){
		if(x[i] - x[nw] <= d){
			dfs(i,gl,ct+1);
		}
	}
}
void solve(){
	int ans=0;
	cin >> n >> d;
	for(int i = 1;i <=n ;i++){
		cin >> x[i];
	}
	if(c <= 2){
		mxans = 1e18;cnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 3;j<=n;j++){
				mxans = 1e18;cnt = 0;
				dfs(i,j,0);
				if(cnt == 2){
					ans++;
					
				}
			}
		}
		cout << ans<<"\n";
	}
	if(c >= 11 && c<=12){
		if(x[2]- x[1]>d){
			cout << 0<<"\n";
		}
		else{
			cout << (n - 3)*(n-2)/2<<"\n";
		}
	}
}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}



