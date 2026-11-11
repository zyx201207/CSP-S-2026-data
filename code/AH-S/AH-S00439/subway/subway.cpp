#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,ans=1e9,tt,w[10005];
vector<int> ls[10005],lt[10005];
vector<int> G[10005];
void dfs(int s,int f){
	if(s==f){
		if(tt<ans){
			ans=tt;
			tt=0;
		}
	}
	for(int i : G[s]){
		for(int j=1;j<=n;j++){
			for(int k : ls[j]){
				if(k==i){
					tt+=lt[j][k];
					dfs(i,f);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		ls[i][0]=0;lt[i][0]=0;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			ls[i].push_back(a);
			lt[i].push_back(b);
			if(j!=1){
				G[a].push_back(ls[i][j-1]);
				G[ls[i][j-1]].push_back(a);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		tt+=w[x];
		tt+=w[y];
		dfs(x,y);
		cout<<ans<<endl;
		}
	return 0;
}

