#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int c,T,n,m,mx,a[N],s[2][N]={0};
void dfs(int w,int k,int p){
	if(w==p) return ;
	for(int i=1;i<=n;i++){
		if(w+i>p) return ;
		if(a[w+i]-a[w]<=m){
			if(s[0][w+i]==k+1) s[1][w+i]++;
			if(s[0][w+i]>k+1) s[0][w+i]=k+1,s[1][w+i]=1;
			dfs(w+i,k+1,p);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) s[0][i]=100000;
		for(int i=1;i<=n;i++) if(a[i]-a[i-1]>m){
			n=i-1;
			break;
		}
		dfs(1,0,n);
		for(int i=1;i<=n;i++) if(s[1][i]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
