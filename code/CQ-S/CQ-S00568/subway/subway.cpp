#include<bits/stdc++.h>
#define pl tuple<int,ll>
#define ll long long
using namespace std;

const int N=505,M=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,q,Cc,Dd;
ll A[M],f[N][N];
vector<pl>dot[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>Cc>>n>>m>>Dd>>q;
	for(int i=1;i<=m;i++)cin>>A[i];
	for(int i=1,k,p;i<=n;i++){
		cin>>k;
		ll w;
		for(int j=1;j<=k;j++){
			cin>>p>>w;
			dot[p].push_back(pl(i,w));
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pl it1:dot[i]){
			for(pl it2:dot[i]){
				int x=get<0>(it1),y=get<0>(it2);
				ll w=get<1>(it1)+get<1>(it2); 
				f[x][y]=min(f[x][y],w);
				f[y][x]=min(f[y][x],w);
			}
		}
	}
	for(int v=1;v<=n;v++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][v]+f[v][j]);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ll ans=inf;
		for(pl it1:dot[x]){
			for(pl it2:dot[y]){
				int a=get<0>(it1),b=get<0>(it2);
				ll w=get<1>(it1)+get<1>(it2); 
				ans=min(ans,w+f[a][b]);
			}
		}
		ans+=A[x]+A[y];
		cout<<ans<<"\n";
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
