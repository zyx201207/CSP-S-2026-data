//GZ-S00238 吴倬然 贵州师范大学云岩实验中学
#include<bits/stdc++.h>
using namespace std;

int ans,c,n,m,d,q,a[500005],w[500005],t[1005][1005],u,v,f[500005];
vector<pair<int,int> > vec[500005];
void dfs(int n,int p,int cnt,int h){
	f[p]=1;
	if(n==p){
		cnt+=w[p];
		ans=min(ans,cnt);
		return ;
	}
	for(auto u:vec[n]){
		if(h==0){
			dfs(u.first,p,cnt+t[u.second][n],u.second);
		}
		else if(h!=u.second&&f[u.first]!=0){		
			if(u.first==p){
				cnt+=t[u.second][u.first];
			}
			dfs(u.first,p,cnt+t[u.second][n]+t[u.second][u.first],u.second);
		}
		else if(h==u.second&&u.first!=p&&f[u.first]!=0){		
			dfs(u.first,p,cnt,u.second);
		}
		else if(h==u.second&&u.first==p&&f[u.first]!=0){	
			dfs(u.first,p,cnt+t[u.second][u.first],u.second);
		}
	}
	f[p]=0;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		for(int j=1; j<=k; j++){
			cin>>a[j]>>t[i][j];
			if(j!=1){
				vec[a[j]].push_back({a[j-1],i});
				vec[a[j-1]].push_back({a[j],i});	
				cout<<a[j]<<' '<<a[j-1]<<endl;			
			}			
		}
	}
	for(int i=1; i<=q; i++){
		cin>>u>>v;
		ans=INT_MAX;
		for(int j=1; j<=n; j++){
			f[j]=0;
		}
		dfs(u,v,w[u],0);
		cout<<ans<<endl;
	}
return 0;
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
