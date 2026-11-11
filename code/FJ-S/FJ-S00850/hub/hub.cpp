#include<stdio.h>
int c,t,e[140][140],d[140][140],n,k,u,V,s;
bool v[140],v2[140];
int chs[140],tp;
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
void dfs2(int x){
	if(v2[x])return;
	v2[x]=1;
	for(int i=1;i<=n;++i)
		if(e[x][i]&&v[i])dfs2(i);
}
void dfs(int x){
	if(tp>k)return;
	if(x>n){
		if(tp==k){
			int ltk=0,s1,s2=0;
			for(int i=1;i<=k;++i)
				if(!v2[chs[i]])dfs2(chs[i]),++ltk;
			if(ltk<=2){
				for(int i=1;i<=n;++i){
					if(!v[i]){
						s1=1145141919.810;
						for(int j=1;j<=k;++j)
							s1=min(s1,d[chs[j]][i]);
					}
					s2=max(s1,s2);
				}
				s=min(s,s2);
			}
		}
		for(int i=1;i<=n;++i)v2[i]=0;
		return;
	}
	chs[++tp]=x,v[x]=1;
	dfs(x+1);
	--tp,v[x]=0;
	dfs(x+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		s=1145141919.810;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				e[i][j]=i==j?1:0;
		for(int i=1;i<n;++i)scanf("%d%d",&u,&V),e[u][V]=e[V][u]=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i][j]=e[i][j]?1:11451419.19810;
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		dfs(1);
		printf("%d\n",s);
	}
	return 0;
}
/* 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
