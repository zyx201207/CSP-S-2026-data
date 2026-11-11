#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,u,v,dist[5005][5005],fa[5005],fa1,fa2,maxd,mind,ans;
bool chosen[5005],f;
vector<int> mp[5005];
inline int findfa(int i){
	return ((fa[i]==i)?i:fa[i]=findfa(fa[i]));
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			mp[5005].clear();
			for(int j=1;j<=n;j++){
				dist[i][j]=0x3f3f3f3f3f3f3f;
			}
		}
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
			dist[u][v]=dist[v][u]=1;
			if(i<=n-k){
				chosen[i]=0;
			}else{
				chosen[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[i][k]+dist[j][k];
					}
				}
			}
		}
		do{
			for(int i=1;i<=n;i++){
				fa[i]=i;
			}
			for(int i=1;i<=n;i++){
				if(chosen[i]){
					for(auto j:mp[i]){
						if(chosen[j]){
							fa[findfa(j)]=fa[i];
							fa1=fa[i];
						}
					}
				}
			}
			fa2=0;
			f=1;
			for(int i=1;i<=n;i++){
				if(chosen[i]){
					if(findfa(i)!=fa1){
						if(fa2){
							f=0;
							break;
						}else{
							fa2=fa[i];
						}
					}
				}
			}
			maxd=0;
			ans=0x3f3f3f3f3f3f3f;
			if(f){
				for(int i=1;i<=n;i++){
					if(!chosen[i]){
						mind=0x3f3f3f3f3f3f3f;
						for(int j=1;j<=n;j++){
							if(chosen[j]){
								mind=min(mind,dist[j][i]);
							}
						}
						maxd=max(maxd,mind);
					}
				}
				ans=min(ans,maxd);
			}
		}while(next_permutation(chosen+1,chosen+1+n));
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
