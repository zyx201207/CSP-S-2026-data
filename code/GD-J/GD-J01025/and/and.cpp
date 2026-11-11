#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
bool vis[N][34],v[N];
vector<int> s;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i];
		int k=0;
		while(t){
			if(t&1)vis[i][k]=1;
			t>>=1;
			k++;
		}
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!v[j]&&vis[j][i]){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!v[j]&&!vis[j][i]){
					v[j]=1;
				}
			}
			ans|=(1<<i);
		}
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _=1;
	//cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
	return 0;
}
