#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
map<pair<int,int>,long long>t;
vector<int>e[500005];
long long de[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a1,t1;
			scanf("%d%d",&a1,&t1);
			t[{i,a1}]=t1;
			e[a1].push_back(i);
		}
	}
	memset(de,0x3f,sizeof(de));
	for(int i=1;i<=m;i++){
		for(int u:e[i]){
			for(int v:e[i]){
				if(u!=v){
					de[u][v]=min(de[u][v],t[{u,i}]+t[{v,i}]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		de[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				de[j][k]=min(de[j][k],de[j][i]+de[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		long long mn=9223372036854775807;
		for(int u:e[x]){
			for(int v:e[y]){
				mn=min(mn,t[{u,x}]+t[{v,y}]+de[u][v]+w[x]+w[y]);
			}
		}
		printf("%lld\n",mn);
	}
	return 0;
}
