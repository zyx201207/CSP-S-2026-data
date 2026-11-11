#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qq,T;
	cin>>c>>n>>m>>d>>qq;
	long long w[m+9];
	int fa[m+9][d+9];
	vector<vector<int> > g(m+9);
	vector<vector<int> > dt(m+9);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;T=t;
			fa[a][i]=t;
			g[a].push_back(i);
			dt[i].push_back(a);
		}
	}
	while(qq--){
		int b[n+9];
		for(int i=1;i<=n+2;i++){
			b[i]=0;
		}
		queue<int> q;
		int l,r,bb=-1;
		cin>>l>>r;
		for(int i=0;i<g[l].size();i++){
			q.push(g[l][i]);
			b[g[l][i]]=1;
		}
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<dt[x].size();i++){
				if(r==dt[x][i]){
					cout<<b[x]*2*T+w[l]+w[r]<<endl;
					bb=1;break;
				}
				if(g[dt[x][i]].size()>1){
					for(int j=0;j<g[dt[x][i]].size();j++){
						if(b[g[dt[x][i]][j]]==0){
							b[g[dt[x][i]][j]]=b[x]+1;
							q.push(g[dt[x][i]][j]);
						}
					}
				}
			}
			if(bb==1)break;
		}
	}
	return 0;
}
