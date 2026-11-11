#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s,w[500008],v[500008],vv[500008],t[508][500008],k[508],a[508][500008],x,y;
vector<int> g[500008];
vector<int> f[500008];
void dfs(int xx,int l){
	if(xx==y){
		s+=w[y];
		return;
	}s+=t[l][xx];
	for(int i=0;i<g[xx].size();i++){
		if(!v[g[xx][i]]){
			v[g[xx][i]]=1;
			s+=t[l][g[xx][i]];
			for(int j=0;j<f[g[xx][i]].size();j++){
				if(vv[f[g[xx][i]][j]]!=0){
					vv[f[g[xx][i]][j]]=1;
					dfs(g[xx][i],f[g[xx][i]][j]);
					vv[f[g[xx][i]][j]]=0;
				}	
			}
			v[g[xx][i]]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[j].push_back(i);
			if(j>1){
				for(int o=1;o<j;o++){
					g[a[i][o]].push_back(a[i][j]);
					g[a[i][j]].push_back(a[i][o]);
				}
			}
		}
	}for(int i=1;i<=q;i++){
		cin>>x>>y;
		s+=w[x];
		v[x]=1;
		for(int j=0;j<f[x].size();j++){
			vv[f[x][j]]=1;
			dfs(x,f[x][j]);
			vv[f[x][j]]=0;
		}
		v[x]=0;
		cout<<s<<endl;
		s=0;
	}
	return 0;
}
