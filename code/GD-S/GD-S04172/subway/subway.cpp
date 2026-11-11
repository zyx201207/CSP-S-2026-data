#include <bits/stdc++.h>
using namespace std ;
const long long   N =  2e3+510;
const long long MAXN=5e16;

long long  dis[N][N] , w[N];
long long  n,m,c,d,q,st,ed;



//第 i 条线路对应点 ： m+i
int  main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(long long  i =1;i<=m;i++){
		cin>>w[i];
		
	}
	for(long long  i=1;i<=n+m;i++){
		for(long long  j = 1;j<=n+m;j++){
			if(i!=j)dis[i][j] = MAXN;
			
		}
	}
	for(long long  i =1;i<=n;i++){
		long long  k ;
		cin>>k;
		for(long long  j =1;j<=k;j++){
			long long  x,y;
			cin>>x>>y;
			dis[i+m][x] = dis[x][i+m] = y;
			
						
		}
	}
	for(long long  k=1;k<=n+m;k++){
		for(long long  i =1;i<=n+m;i++){
			for(long long  j =1;j<=n+m;j++){
			     dis[i][j] = min(dis[i][j] , dis[i][k] +dis[k][j]);
				
			}
		}
	}
	
	while(q--){
		cin>>st>>ed;
		cout<<dis[st][ed] + w[st]+w[ed]<<'\n';
		
	}
	return 0;
	
}

