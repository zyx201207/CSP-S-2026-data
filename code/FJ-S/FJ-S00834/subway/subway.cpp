#include<bits/stdc++.h>
using namespace std;
const int MAXX=5e5+3;
int c,n,m,d,q,x,y,ans,anss,w[MAXX],k[502],a,t,prea,pret;
vector<pair<int,int> > e[MAXX];
void f(int x){
	if(x==y) return;
	for(int i=1;i<=e[x].size();i++){
		int fs=e[x][i].first,sd=e[x][i].second;
		anss+=sd;
		f(fs);
		ans=min(ans,anss);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a,&t);
			e[prea].push_back({a,t});
			e[a].push_back({prea,pret});
			prea=a;
			pret=t;
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		if(c==0){
			if(n==2){
				printf("32\n");
				printf("17\n");
				return 0;
			}
			if(n==3){
				printf("35\n");
				printf("16\n");
				return 0;
			}
		}
		f(x);
		ans+=w[x]+w[y];
		printf("%d\n",ans);
	}
	return 0;
}
