#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],x1,x2,ni[501][500001],summin;
vector<int> v[501];

void dfs(int t,int node,int ani){
	if(t>=summin) return ;
	if(node==x2){summin=t;return ;}
	for(int i=1;i<=n;i++)
		if(ni[i][node]&&ani!=i)
			for(int j=0;j<v[i].size();j++){
				if(v[i][j]==node||!ni[i][v[i][j]]) continue;
				dfs(t+ni[i][node]+ni[i][v[i][j]],v[i][j],i);
			}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x1,&x2);
			ni[i][x1]=x2;
			v[i].push_back(x1);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x1,&x2);
		summin=1000001;
		dfs(w[x1]+w[x2],x1,0);
		printf("%d\n",summin);
	}
	return 0;
}
