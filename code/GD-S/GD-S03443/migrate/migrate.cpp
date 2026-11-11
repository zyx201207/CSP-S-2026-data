#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N],n,d,c,ans,cnt,minx=N+20;
vector<int> g[N];
void dfs(int u,int fa,int t,int s){
	if(s>minx) return ;
	//cout << "u="<<u<<"\n";
	if(u==t){
		minx=min(minx,s);	
		return ;
	}
	for(int v: g[u]){
		//if(v==fa) continue ;
		dfs(v,u,t,s+1);
	}
}
void dfs2(int u,int fa,int t,int s){
	if(s>minx) return ;
	//cout << "u="<<u<<"\n";
	if(u==t){
		if(s==minx) cnt++;	
		//cout << "s="<<s<<"\n";
		return ;
	}
	for(int v: g[u]){
		//if(v==fa) continue ;
		dfs2(v,u,t,s+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >>c>> T;
	while(T--){
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d&&i!=j) g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			//cout << "===================\n";
			
			for(int j=i+2;j<=n;j++) if(i!=j){
				minx=N+20,cnt=0;
				dfs(i,0,j,0);
				dfs2(i,0,j,0);
				//cout << "i="<<i<<" j="<<j<<" "<<"cnt="<<cnt<<" minx="<<minx<<"\n";
				if(cnt==2) ans++;
			}
		}
		cout << ans<<"\n";
	} 
	
	
	return 0;
}
