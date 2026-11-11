#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,dd;
long long a[N];
int ans[310][310][310];
void dfs(int d,int u,int s){
	ans[d][u][s]++;
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]<=dd){
			dfs(d,i,s+1);	
		} 
	}
}
void solve(){
	int anser=0;
	cin>>n>>dd;
	if(n>9){
		cout<<0<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,i,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int k=0;
			while(ans[i][j][k]==0) k++; 
			if(ans[i][j][k]==2) anser++;
		}
	}
	cout<<anser<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(ans,0,sizeof(ans));
		solve();
	}
}
