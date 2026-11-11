#include<bits/stdc++.h>
#define N 500009
#define ll long long
using namespace std;ll d[1009][1009],x,y,inf=1e18;
int c,n,m,d1,q2,i,w[N],k[509],j,k1[509],v[1001][1001],v1[1001][509];
vector<int>q[509];vector<array<ll,2>>p[509],son[N];
priority_queue<array<ll,3>>q1; 
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d1,&q2);
	for(i=1;i<=m;i++)scanf("%d",&w[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&k[i]);k1[i]=k1[i-1]+k[i];
		for(j=1;j<=k[i];j++)
			scanf("%d%d",&x,&y),p[i].push_back({x,y}),son[x].push_back({i,j});
	}if(k1[n]>1000)return 0;
	//cout<<son[57][1][0]<<" "<<son[57][1][1];
	for(i=1;i<=m;i++){
		for(j=1;j<=k1[n];j++)d[i][j]=inf;
		//for(j=1;j<=n;j++)v1[i][j]=k[j];
		for(auto j:son[i])
			q1.push({-(d[i][k1[j[0]-1]+j[1]]=p[j[0]][j[1]-1][1]),j[0],j[1]});
		while(q1.size()){
			auto x=q1.top();q1.pop();x[0]=-x[0];
			//cout<<x[1]<<" "<<x[2]<<" "<<x[0]<<"\n";
			if(v[i][k1[x[1]-1]+x[2]])continue;
			v[i][k1[x[1]-1]+x[2]]=1;
			if(!v1[i][x[1]]){
				for(j=0;j<k[x[1]];j++)if(j!=x[2]-1)
					q1.push({-(d[i][k1[x[1]-1]+j+1]=x[0]+p[x[1]][j][1]),x[1],j+1});
				v1[i][x[1]]=1;
			}for(auto j:son[p[x[1]][x[2]-1][0]]){
				if(!v[i][k1[j[0]-1]+j[1]]&&d[i][k1[j[0]-1]+j[1]]>x[0]+p[j[0]][j[1]-1][1])
					q1.push({-(d[i][k1[j[0]-1]+j[1]]=x[0]+p[j[0]][j[1]-1][1]),j[0],j[1]});
				//cout<<x[1]<<" "<<x[2]<<" "<<k1[j[0]-1]+j[1]<<"\n";
			}
		}
	}while(q2--){
		scanf("%d%d",&x,&y);ll ans=inf;
		for(auto i:son[y])ans=min(ans,d[x][k1[i[0]-1]+i[1]]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
