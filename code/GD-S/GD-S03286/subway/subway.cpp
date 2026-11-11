#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500001];
vector<long long> a[501];
vector<long long> t[501];
long long k[501];

vector<pair<long long,long long>> g[1001];//经过的线路 站点到线路距离 
long long tu[1001][1001]; //距离 
long long to[501];//本线是否走过 
int lit[1001];//本站是否处理过 
void flo(int st){
	int l=st;//当前处理点 
	long long sss=m-1;//未处理站点数 
	while(sss){
		lit[l]=1;
		int sum=g[l].size();//经过线路数 
		for(int i=0;i<sum;i++){
			int bi=g[l][i].first;//线路编号 
			if(to[bi]) continue;
			to[bi]=1;
			int len=a[bi].size();//线路经过站点数 
			for(int j=0;j<len;j++){
				int x=a[bi][j]; //去往点 
				tu[l][x]=min(tu[l][x],g[l][i].second+t[bi][j]);
				tu[x][l]=min(tu[x][l],g[l][i].second+t[bi][j]);
//				cout<<l<<' '<<x<<' '<<tu[l][x]<<"\n"; 
			}
		}
		for(int i=1;i<=m;i++){
				tu[st][i]=min(tu[st][i],tu[st][l]+tu[l][i]);
				tu[i][st]=min(tu[i][st],tu[st][l]+tu[l][i]);	
//				cout<<i<<' '<<j<<' '<<tu[i][j]<<"\n"; 
		}
		long long zhbi=0,zhi=1e18;
		for(int i=2;i<=m;i++){
			if(!lit[i]){
				if(tu[st][i]<zhi){
					zhi=tu[st][i];
					zhbi=i;
				}
			}
		}
		l=zhbi;
		sss--;
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			g[x].push_back({i,y}); 
		}
	}
	if(c<=11){
		for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) if(i!=j) tu[i][j]=1e18;
		for(int i=1;i<=m;i++)
			flo(i);
		for(;q--;){
			int xx,yy;
			cin>>xx>>yy;
			cout<<tu[xx][yy]+w[xx]+w[yy]<<"\n";
		}
	}
	return 0;
}
