#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int rd(){
	int x=0;
	int f=1;
	char c=getchar();
	if(c=='-') f=-1;
	else x=(c^48);
	while(1){
		char c=getchar();
		if(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48);
		else break;
	}
	return x*f;
}
int c,n,m,d,q;
const int M=5e5+10,N=510;
int w[M];
vector<pii> e[N+M];
int k[N];
int dis[N][N],ww[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++) w[i]=rd();
	for(int i=1;i<=n;i++){
		int id=i+m;
		k[i]=rd();
		for(int j=1,v,w;j<=k[i];j++){
			v=rd(),w=rd();
			e[id].push_back({v,w});
			e[v].push_back({id,w}); 
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			ww[i][j]=1e18;
		}	
	}
	for(int i=1;i<=n;i++){
		for(pii p1:e[i+m]){
//			cout<<"与"<<i+m<<"相邻的："<<p1.fi<<"\n";
			for(pii p2:e[p1.fi]){
				ww[i][p2.fi-m]=ww[p2.fi-m][i]=min(ww[p2.fi-m][i],p1.se+p2.se);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<ww[i][j]<<" ";
//		}
//		cout<<"\n"; 
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			dis[i][j]=ww[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				dis[x][y]=min(dis[x][y],dis[x][k]+dis[k][y]);
			}
		}
	}
//	cout<<dis[1][2]<<"\n";
	while(q--){
		int x,y;
		x=rd(),y=rd();
		int ans=1e18;
		for(pii p1:e[x]){
			for(pii p2:e[y]){
//				cout<<"dis:"<<p1.fi-m<<" "<<p2.fi-m<<" "<<p1.se<<" "<<p2.se<<"\n";
				ans=min(ans,dis[p1.fi-m][p2.fi-m]+p1.se+p2.se);
			}
		}
//		cout<<ans<<"\n";
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
把同一个地铁可以经过的连上超源
这个超源的个数是n的，即500个 
注意到d<=20
qd是可以的

不对我是傻逼吗

我想了个qd^2然后一直认为是4e9的

我草 

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

