#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10,INF=1e18;
int n,m,a[N],sw[N][35],vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int id=0;
		int j=a[i];
		for(int k=1;k<=32;k++){
			sw[i][k]=(j&1);
			j=(j>>1);
		}
	}
	int ans=0;
	for(int i=32;i>=1;i--){
		int cnt=0;
		vector<int>g;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				continue;
			}
			if(sw[j][i]==1){
				cnt++;
			}else{
				g.push_back(j);	
			}
		}
		if(cnt>=m){
			ans+=(1<<(i-1));
			for(auto e:g){
				vis[e]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
