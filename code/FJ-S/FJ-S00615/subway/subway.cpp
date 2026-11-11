#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct stai{
	int a,t;
}sta[501][2001];
int c,n,m,d,q;
ll w[N];
int f[501][2001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int i,j;
	for(i=1;i<=m;i++) scanf("%lld",&w[N]);
	for(i=1;i<=n;i++){
		int k;
		cin>>k;
		for(j=1;j<=k;j++){ 
			scanf("%d%d",&sta[i][j].a,&sta[i][j].t); 
			f[i][sta[i][j].a]=1;
		}
	}
	while(q--){
		int from,to,ans=0;
		scanf("%d%d",&from,&to);
		ans+=w[from]+w[to];
		if(c>=12&&c<=19){
			for(i=1;i<=n;i++){
				if(f[i][sta[i][from].a]==1&&f[i][sta[i][to].a]==1){
					ans+=sta[1][1].t*4;
					break;
				}
			} 
			ans+=sta[1][1].t*6;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
