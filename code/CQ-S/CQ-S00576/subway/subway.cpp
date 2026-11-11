#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
struct node{
	int i,t;
	node(int x=0,int y=0){
		i=x;
		t=y;
	}
};
int c,n,m,d,q;
int w[N],ni[505],dis[501][501];
vector<int>a[501],t[501];
vector<node>s[N],e[501];
void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i)scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&ni[i]);
		for(int j=1;j<=ni[i];++j){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			s[x].push_back(node(i,y));
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=0;j<a[i].size();++j){
//			printf("%d %d %d %d\n",i,j,a[i][j],t[i][j]); 
//		}
//	}
//	for(int i=1;i<=m;++i){
//		printf("%d\n",w[i]);
//		for(int j=0;j<s[i].size();++j){
//			printf("%d %d\n",s[i][j].i,s[i][j].t);
//		}
//	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<a[i].size();++j){
			int x=s[a[i][j]].size();
			if(x==1)continue;
//			printf("%d %d %d %d\n",i,j,x,a[i][j]);
			for(int k=0;k<x;++k){
				for(int l=k+1;l<x;++l){
					node kk=s[a[i][j]][k],ll=s[a[i][j]][l];
//					printf("%d %d %d %d\n",i,j,dis[kk.i][ll.i],dis[ll.i][kk.i]);
					dis[kk.i][ll.i]=min(dis[kk.i][ll.i],kk.t+ll.t);
					dis[ll.i][kk.i]=min(dis[ll.i][kk.i],kk.t+ll.t);
				}
			}
		}
	}
	floyd();
	for(int i=1;i<=q;++i){
		int xr,yr;
		scanf("%d%d",&xr,&yr);
		int ans=1e9;
		for(int i=0;i<s[xr].size();++i){
			for(int j=0;j<s[yr].size();++j){
				printf("%d %d %d %d\n",ans,s[xr][i].t,s[yr][j].t,dis[s[xr][i].i][s[yr][j].i]);
//				printf("%d %d\n",
				ans=min(ans,s[xr][i].t+s[yr][j].t+dis[s[xr][i].i][s[yr][j].i]);
//				printf("%d %d %d %d\n",ans,s[xr][i].t+dis[s[xr][i].i][s[yr][j].i]+s[yr][j].t,w[xr],w[yr]);
			}
		}
		printf("%d\n",ans+w[xr]+w[yr]);
	} 
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
