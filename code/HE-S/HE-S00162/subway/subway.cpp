#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int> son[N];
int zw[N],w[N][N],to[N],tw[N];
bool v[N];
int dfs(int x,int y){
	if(w[x][y]!=0)return w[x][y];
	int ans=0x3f3f3f3f;
	for(auto dy:son[x]){
		if(v[dy]==false){
			v[dy]=true;
			ans=min(ans,dfs(dy,y)+w[x][dy]);
			v[dy]=false;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>zw[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>to[j]>>tw[j];
			for(int g=1;g<j;g++){
				if(w[to[j]][to[g]]==0){
				son[to[j]].push_back(to[g]);
				son[to[g]].push_back(to[j]);
				} 
				if(w[to[j]][to[g]]!=0){
					w[to[j]][to[g]]=min(w[to[j]][to[g]],tw[j]+tw[g]);
				w[to[g]][to[j]]=w[to[j]][to[g]];
				}
				else{
					w[to[j]][to[g]]=tw[j]+tw[g];
				w[to[g]][to[j]]=w[to[j]][to[g]];
				}				
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=zw[x]+zw[y];
		v[x]=true;
		ans+=dfs(x,y);
		cout<<ans<<"\n";
		v[x]=false;
	}
	return 0;
} 
