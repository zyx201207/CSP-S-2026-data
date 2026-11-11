#include<bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
struct Node{
	int v,t;
};
vector<Node>g[500010];
int c,n,m,d,p;
int w[500010];
int k[500010];
int dao[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(re int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(re int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(re int j=1;j<=k[i];j++){
			int a,t;
			scanf("%d%d",&a,&t);
			g[i].push_back({a,t});
			dao[a]=i;
		}
	}
	ll sum=0;
	int x,y;
	while(p--){
		scanf("%d%d",&x,&y);
		sum+=w[x]+w[y];
		for(auto i:g[dao[x]]){
			if(i.v==y)sum+=i.t;
			if(i.v==x)sum+=i.t;
		}
	}
	printf("%lld",sum);
	return 0;
}
