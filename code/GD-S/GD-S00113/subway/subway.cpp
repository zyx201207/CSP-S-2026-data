#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q,x,y,w[500005],dis[505][505];
struct S{
	long long a,t;
};vector<S> sub[505]; 
void getdis(int l){
	for(int x=0;x<sub[l].size();x++){
		for(int y=0;y<sub[l].size();y++){
			dis[sub[l][x].a][sub[l][y].a]=dis[sub[l][y].a][sub[l][x].a]=min(dis[sub[l][x].a][sub[l][y].a],sub[l][x].t+sub[l][y].t);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1,a,t,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d %d",&a,&t);
			sub[i].push_back({a,t});
		}
	}
	if(c>=7&&c<=11){
		while(q--){
			long long res;
			scanf("%lld %lld",&x,&y);
			for(int l=1;l<=n;l++){
				for(int X=0;X<sub[l].size();X++){
					if(sub[l][X].a==x)res+=sub[l][X].t;
					if(sub[l][X].a==y)res+=sub[l][X].t;
				}
			}
			printf("%lld\n",w[x]+w[y]+res);
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)dis[i][j]=2e12;
	}
	for(int i=1;i<=n;i++)getdis(i);
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			} 
		}
	}
	while(q--){
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",w[x]+w[y]+dis[x][y]);
	}
	return 0;
}
