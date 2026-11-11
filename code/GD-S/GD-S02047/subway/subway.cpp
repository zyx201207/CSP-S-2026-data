#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=5e5+10, M=505;
ll n,m,d,q,w[N],f[M][M],x,y,k,ans;
struct huan{
	ll u,v;//u到哪条线 v代价 
};
vector<huan>v[N];
int main(){//freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];//复杂的建图 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			v[x].pb({i,y});//重点1 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) f[i][j]=(1e17);
		}
	}
	for(int i=1;i<=m;i++){//将站厅压缩掉 1.换乘压缩为边  2.地铁口直接连接几号线(答案处理时) 
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				f[v[i][j].u][v[i][k].u]=v[i][j].v+v[i][k].v;
				f[v[i][k].u][v[i][j].u]=v[i][j].v+v[i][k].v;//重点2 
			} 	
		}
	}//重点3：雷霆floyd 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){//重点4：癫疯处理 
		cin>>x>>y, ans=(1e17);
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,w[x]+v[x][i].v+f[v[x][i].u][v[y][j].u]+w[y]+v[y][j].v);
			}//进站+换乘.....+出站 
		}cout<<ans<<'\n';
	}
	return 0;
}
/*
复杂度O(d^2(m+q)+n^3) 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
