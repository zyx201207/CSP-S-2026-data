#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
long long c,t,n,d,x[N],ans,mx,vis[N],mn;
void fA(){
	long long r=d/(x[2]-x[1]);
	ans=n-(r+r-1);
}
void dfs(int p,int ed,long long res){
	if(p==ed){
		mx=max(mx,res);
		mn=min(mn,res);
		vis[res]++;
	}
	for(int i=1;p+i<=ed;i++){
		int u=i+p;
		if(x[u]-x[p]<=d){
			dfs(u,ed,res+1);
		}
	}
}
void solve(){
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			mx=0;
			mn=2e6+2;
			dfs(i,j,0);
			if(vis[mn]==2){
				ans++;
			}
			for(int k=1;k<=mx;k++){
				vis[k]=0;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12)fA();
		else solve();
		cout<<ans<<endl;
	}
	return 0;
}
