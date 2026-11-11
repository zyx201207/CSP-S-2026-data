#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
ll c,n,m,d,q,dis[N][N],a[N];

struct node{
	ll id,v;
}xl[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int k,i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&xl[j].id,&xl[j].v);
		}
		for(int i1=1;i1<=k;i1++){
			for(int j1=i1+1;j1<=k;j1++){
				dis[xl[j1].id][xl[i1].id]=dis[xl[i1].id][xl[j1].id]=min(dis[xl[i1].id][xl[j1].id],xl[i1].v+xl[j1].v);
			}
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) dis[i][j]=0;
				else dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	
	for(int x,y,i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%lld\n",a[x]+a[y]+dis[x][y]);
	}
	
	
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
