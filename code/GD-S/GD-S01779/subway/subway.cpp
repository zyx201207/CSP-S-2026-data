#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],b[500005],t[505][500005];
vector <pair<int,int> > k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	while(n--){
		int x,v,t;
		scanf("%d",&x);
		for(int i = 1;i <= x;i++){
			scanf("%d%d",&v,&t);
			k[x].push_back({v,t});
		}
	}
	while(q--){
		int u,v,sum = 0;
		scanf("%d%d",&u,&v);
		printf("%d\n",w[u]+w[v]);
	}
	return 0;
}

