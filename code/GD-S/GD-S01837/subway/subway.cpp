#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
struct node{
	int id,t;
};
int w[M];//口到厅 
int k[N];//每条线路的站数 
vector<int>a[N],t[N];
vector<node>q[M];//每个站的线路及去站台的时间 
//n条线路 m个站 每站最多d条  
int op,n,m,d,T;
int f[M];
queue<int>qu;
bool b[M];
map<int,int>mp;
void chuli(int x){
	while(!qu.empty())qu.pop();
	qu.push(x);
	int u,xian,ti,v,tim;
	node nn;
	memset(f,63,sizeof(f));
	memset(b,false,sizeof(b));
	f[x]=0;
	while(!qu.empty()){
		u=qu.front();
		qu.pop();
		b[u]=true;
		for(int i=0;i<q[u].size();i++){
			nn=q[u][i];
			ti=nn.t;
			xian=nn.id;
			for(int j=0;j<a[xian].size();j++){
				v=a[xian][j];
				tim=t[xian][j];
				if(v==u)continue;
				if(f[v]>f[u]+ti+tim){
					f[v]=f[u]+ti+tim;
					if(!b[v]){
						b[v]=true;
						qu.push(v);
					}
				}
			}
		}
		b[u]=false;
	}
	for(int i=1;i<=m;i++){
		u=i,v=x;
		if(u>v)swap(u,v);
		mp[u*M+v]=f[i];
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>op>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			a[i].push_back(u);
			t[i].push_back(v);
			q[u].push_back((node){i,v});
		}
	}
	while(T--){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		if(mp[x*M+y]>0)f[y]=mp[x*M+y];
		else chuli(x);
		cout<<f[y]+w[x]+w[y]<<"\n";
	}
	return 0;
} 
/*
Oct31==Dec25?
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
