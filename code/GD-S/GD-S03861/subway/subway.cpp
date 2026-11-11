#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,p,m1[500002],n1[502],ans;
struct STD{
	int a;
	int b;
}d1[22][502];
void dfs(){
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%%d%d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++) scanf("%d",m1[i]);	
	for(int i=1,k;i<=n;i++){
		scanf("%d",k);
		for(int i=1;i<=k;i++){
			scanf("%d%d",&d1[i][k].a,&d1[i][k].b);
		}
	}
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans=0;
		ans=m1[x]+m1[y];
		printf("%d\n",ans);
	}
	return 0;
}
