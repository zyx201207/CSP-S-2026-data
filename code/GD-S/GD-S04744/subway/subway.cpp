//subway
#include<bits/stdc++.h>
#define p_b push_back
typedef long long ll;
using namespace std;
const int N=5e2+55,M=5e5+55;
const ll inf=1e17;
int sub,n,m,d,q;
ll a[M],dis[N][N];
struct Node{
	int id;
	ll len;
};
vector<Node>b[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>sub>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			ll y;
			cin>>x>>y;
			b[x].p_b((Node){i,y});
		}
	}
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(Node x:b[i]){
			for(Node y:b[i]){
				if(x.id==y.id) continue;
				dis[x.id][y.id]=min(dis[x.id][y.id],x.len+y.len);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;//同一条线不需要换线 
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}//floyd求全源最短路 
	while(q--){
		int st,ed;
		cin>>st>>ed;
		ll ans=inf;
		for(Node x:b[st]){
			for(Node y:b[ed]){
				ans=min(ans,dis[x.id][y.id]+x.len+y.len);//从st站的x.id线到ed站的y.id线(从站厅到线) 
			}
		}
		ans+=a[st]+a[ed];//还要到站厅
		cout<<ans<<"\n"; 
	}
	return 0;
}
/*
AC ver.
注意只求步行时间.
将每条线路看作一个点,建图 
时间瓶颈在于建图,O(m*d^2),2e8,应该可接受 

0 2 5 20 2
4 1 9 2 5
3 
1 5 
2 7 
4 6
3 
2 3 
3 4 
5 7
1 3
1 2
*/

