#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
namespace yyh{
	int sub,n,m,dd,q,a[500005];
	vector<pair<int,int>>g[505];
	vector<int>o[500005];
	map<int,int>w[505];
	map<int,int>gw[505];
	int d[505][505];
	bool v[505];
	priority_queue<pair<int,int>>p;
	void dij(int *d,int v0){
		for(int i=1;i<=n;i++)d[i]=1e18,v[i]=0;
		d[v0]=0;
		p.push({0,v0});
		while(!p.empty()){
			int k=p.top().second;
			p.pop();
			if(v[k])continue;
			v[k]=1;
			for(pair<int,int>t:g[k]){
				int j=t.first,w=t.second;
				if(d[j]>d[k]+w){
					d[j]=d[k]+w;
					p.push({-d[j],j});
				}
			}
		}
	}
	signed main(){
		cin>>sub>>n>>m>>dd>>q;
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				w[i][x]=y;
				o[x].push_back(i);
			}
		}
		for(int i=1;i<=m;i++)
			for(int j=0;j<(int)o[i].size();j++)
				for(int k=j+1;k<(int)o[i].size();k++){
					int x=o[i][j],y=o[i][k];
					int val=w[x][i]+w[y][i];
					if(x>y)swap(x,y);
					if(!gw[x].count(y))gw[x][y]=val;
					else gw[x][y]=min(gw[x][y],val);
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(!gw[i].count(j))continue;
				int val=gw[i][j];
				g[i].push_back({j,val});
				g[j].push_back({i,val});
			}
		for(int i=1;i<=n;i++)dij(d[i],i);
		while(q--){
			int x,y;
			cin>>x>>y;
			int ans=1e18;
			for(int j:o[x])for(int k:o[y])ans=min(ans,d[j][k]+w[j][x]+w[k][y]);
			cout<<ans+a[x]+a[y]<<endl;
		}
		return 0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	yyh::main();
	cerr<<"Time: "<<(double)clock()<<"ms";
	return 0;
}
/*
g++ -std=c++14 -O2 -Wl,-stack=100000000 subway.cpp -o subway.exe
subway.exe < subway1.in > a.out
fc a.out subway1.ans
subway.exe < subway2.in > a.out
fc a.out subway2.ans
subway.exe < subway3.in > a.out
fc a.out subway3.ans
subway.exe < subway4.in > a.out
fc a.out subway4.ans
subway.exe < subway5.in > a.out
fc a.out subway5.ans
subway.exe < subway6.in > a.out
fc a.out subway6.ans
subway.exe < subway7.in > a.out
fc a.out subway7.ans

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
