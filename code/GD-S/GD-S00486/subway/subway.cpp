#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int c,n,m,d,q;
int k[505],v[505][500005],t[505][500005],r,ans,s,w[500005];
bool vis[500005];
void dfs(int x,int sum,int id){
	if(sum > s) return;
	if(x==r){
		s=min(s,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=1;j<=k[i];j++){
			if(v[i][j]==x){
				f=1;
				break;
			}
		}
		if(f){
			if(id == i){
				for(int j=1;j<=k[i];j++){
					if(!vis[v[i][j]]){
						vis[v[i][j]]=1;
						dfs(v[i][j],sum,id);
					}
				}
			}else{
				for(int j=1;j<=k[i];j++){
					if(!vis[v[i][j]]){
						vis[v[i][j]]=1;
						dfs(v[i][j],sum+t[i][j]+t[i][x]+(id!=-1?t[id][x]:0),i);
					}
				}
			}
		}
	}
}
int main(){
	fastio;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v[i][j]>>t[i][j];
		}
	}
	while(q--){
		int l,r;
		memset(vis,0,sizeof(vis));
		s=INT_MAX;
		cin>>l>>r;
		ans=w[l]+w[r];
		vis[l]=1;
		dfs(l,0,-1);
		cout<<ans+s<<endl;
	}
	return 0;
}
