#include<bits/stdc++.h>
#define p make_pair
using namespace std;
int c,n,m,D,Q,w[500005],t[505][25];
vector<int> d[505];
vector<pair<int,int> > e[40005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		d[i].push_back(a);
		t[a][i]=b;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(j==k) continue;
				e[j].push_back(p(k,t[j][i]+t[k][i]));
				e[k].push_back(p(j,t[j][i]+t[k][i]));
			}
		}
	}
	while(Q--){
		queue<pair<int,int> > q;
		int s,e,dis[500005],vis[500005];
		scanf("%d%d",&s,&e);
		for(int i=1;i<=m;i++){
			dis[i]=1<<30;
			vis[i]=0;
		}
		q.push(p(s,0));
		while(!q.empty()){
			
		}
	}
	return 0;
}
