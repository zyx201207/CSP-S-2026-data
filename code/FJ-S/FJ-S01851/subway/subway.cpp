#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
const ll M=1000000005; 
ll T;//T为总时间
ll c,n,m,d,q,k,x[N],y[N],a,t;//n条线m个厅
ll w[N];//地铁口i到厅i时间
ll u[N][N];//q[厅][线路]=时间 
ll g[N][N];//真图 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	ll qk=max(n,m);
	for(int i=1;i<=qk;i++){
		for(int j=1;j<=qk;j++){
			g[i][j]=M;
			u[i][j]=M;
		}
	}
	for(int i=1;i<=m;i++){//w[i]=厅口时间
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//i:几号线路 
		cin>>k;//i线路经过k个厅 
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			u[a][i]=t;
			//a为第a个厅 t为厅a到线路i的时间	
		}
	} 
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i]; 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
			 	g[i][j]=min(u[i][k]+u[j][k],g[i][j]); 
			}
		}
	}
	for(int i=1;i<=q;i++){
		int dx=x[i],dy=y[i];
		T=w[dx]+w[dy]+g[dx][dy];
		cout<<T<<endl; 
	} 
	return 0;
}
//	建一个雷霆floyd图骗分 
//	不维护地铁口
//	合并 不同厅的台？ 
//	厅j -> 厅j2 = t[路线i][厅j]+t[路线i][厅j2] 
//	直接维护厅试试 
//  30min假
//  把线路当成点
//  维护线路和台？ 
//  10min假 
//  维护完再维护台与台？ 
//  10min假
//  给线路丢厅后面？不会 
//  怎么对一半 
//  弃 
