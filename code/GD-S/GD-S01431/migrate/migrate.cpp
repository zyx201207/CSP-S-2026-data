#include<iostream>
#include<cmath>
#define int long long
using namespace std;
const int N=2e6+5,NN=305;
int c,t,n,d,x[N],minn=2e18,cnt=0;
void dfs(int u,int v,int l){
	if(u==v){
		if(l<minn){
			minn=l;
			cnt=1;
		}else if(l==minn){
			cnt++;
		}
	}
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]>d){
			break;
		}
		dfs(i,v,l+1);
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			minn=2e18,cnt=0;
			dfs(i,j,0);
			if(cnt==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
