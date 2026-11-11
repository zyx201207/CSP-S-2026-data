#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 7;

int _, n, m, ans, a[N];
bool vis[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=31;i>=0;i--){
		int op=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if((1<<i)&a[j]){
				op++;
			}
		}
		if(op>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(vis[j])continue;
				if(!((1<<i)&a[j])){
					vis[j]=1;
				}
			}
		}
	}
	cout<<ans;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_ = 1;
	while(_--){
		solve();
	}
}
