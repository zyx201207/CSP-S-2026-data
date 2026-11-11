#include <bits/stdc++.h>
using namespace std;
struct r{
	int a,t;
};
int w[510],k[510];
r x[510][50010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>x[i][j].a>>x[i][j].t;
	}
	while(q--){
		int u,v,min_t=1e9;
		cin>>u>>v;
		bool f=0;
		for(int i=1;i<=n;i++){
			int id1=0,id2=0;
			for(int j=1;j<=k[i];j++){
				if(x[i][j].a==u) id1=j;
				if(x[i][j].a==v) id2=j;
			}
			if(id1!=0 && id2!=0){
				f=1;
				min_t=min(min_t,w[u]+w[v]+x[i][id1].t+x[i][id2].t);
			}
		}
		if(f==0){
			int id1=0,id2=0,id3=0,id4=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(x[i][j].a==u){
						id1=i;
						id3=j;
					}
					if(x[i][j].a==v){
						id2=i;
						id4=j;
					}
				}
			}
			int g=0,id5=0,id6=0;
			for(int i=1;i<=k[id1];i++){
				for(int j=1;j<=k[id2];j++){
					if(x[id1][i].a==x[id2][j].a){
						g=x[id1][i].a;
						id5=i;
						id6=j;
						break;
					}
				}
			}
			cout << w[u]+x[id1][id3].t+x[id1][id5].t+x[id2][id6].t+x[id2][id4].t+w[v];
		}else cout << min_t;
	}
	return 0;
}
