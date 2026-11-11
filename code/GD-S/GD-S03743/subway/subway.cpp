#include <bits/stdc++.h>
#define ll long long
#define N 505
#define Q 100005
#define D 25
#define M 500005
using namespace std;
int c,n,m,d,q;
ll w[M];
struct e{
	int a;
	ll t;
};
vector<e> conv[M];
//int que[Q][2];
ll dis[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int x=1;x<=m;x++)
		cin>>w[x],conv[x].reserve(d);
	for(int x=0,k;x<n;x++){
		cin>>k;
		//ro[x].reserve(k);
		for(int z=0,a,t;z<k;z++){
			cin>>a>>t;
			//ro[x].push_back({a,t});
			conv[a].push_back({x,t});
		}
	}
//	for(int x=0;x<q;x++)
//		cin>>que[x][0]>>que[x][1];
	memset(dis,0x3f,sizeof dis);
	for(int x=0;x<n;x++)
		dis[x][x]=0;
	for(int x=1;x<=m;x++){
		for(int z=0;z<conv[x].size();z++)
			for(int c=0;c<z;c++)
				if(dis[conv[x][z].a][conv[x][c].a]>conv[x][z].t+conv[x][c].t)
					dis[conv[x][z].a][conv[x][c].a]=dis[conv[x][c].a][conv[x][z].a]=conv[x][z].t+conv[x][c].t;
	}
//	for(int x=0;x<n;x++)
//		for(int z=0;z<n;z++)
//			cout<<dis[x][z]<<" \n"[z==n-1];
	for(int k=0;k<n;k++)
		for(int st=0;st<n;st++)
			for(int to=0;to<n;to++)
				dis[st][to]=min(dis[st][to],dis[st][k]+dis[k][to]);
	for(int x=0,l,r;x<q;x++){
		cin>>l>>r;
		ll ans=LLONG_MAX;
//		for(const auto&[l_a,l_t]:conv[l])
//			for(const auto&[r_a,r_t]:conv[r])
//				ans=min(ans,l_t+r_t+dis[l_a][r_a]);
		for(const auto&s:conv[l])
			for(const auto&e:conv[r])
				ans=min(ans,s.t+e.t+dis[s.a][e.a]);
		cout<<ans+w[l]+w[r]<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
