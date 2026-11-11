#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
long long w[M];
struct node{
	int id;
	long long tm;
};
vector<node> vec[M];
long long g[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		g[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int stt;
			long long tm;
			cin>>stt>>tm;
			vec[stt].push_back({i,tm});
		}
	}
	for(int i=1;i<=m;i++){
		for(int r1=0;r1<vec[i].size();r1++){
			for(int r2=r1+1;r2<vec[i].size();r2++){
				node x1=vec[i][r1],x2=vec[i][r2];
				g[x1.id][x2.id]=min(g[x1.id][x2.id],x1.tm+x2.tm);
				g[x2.id][x1.id]=min(g[x2.id][x1.id],x1.tm+x2.tm);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		long long ans=1e18;
		for(int r1=0;r1<vec[st].size();r1++){
			for(int r2=0;r2<vec[ed].size();r2++){
				node x1=vec[st][r1],x2=vec[ed][r2];
				long long cnt=x1.tm+x2.tm+g[x1.id][x2.id]+w[st]+w[ed];
				ans=min(ans,cnt); 
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
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

Oct31==Dec25?
*/
