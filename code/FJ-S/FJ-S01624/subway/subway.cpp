#include<bits/stdc++.h>
#define int long long
#define GP pair<int,int>
#define MP make_pair
using namespace std;int read();
const int N=505,M=500005;
int C,n,m,d,q,qd[M],f[N][N];
vector<GP> v[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) qd[i]=read();
	for(int t=1;t<=n;t++){
		int ls=read();
		while(ls--){
			int x=read();int y=read();
			v[x].emplace_back(MP(t,y));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int t=1;t<=m;t++){
		int ls=v[t].size();
		for(int i=0;i<ls;i++){for(int j=i;j<ls;j++){
			int x=v[t][i].first,y=v[t][j].first;
			f[x][y]=f[y][x]=min(f[x][y],v[t][i].second+v[t][j].second);
		}}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	while(q--){
		int x=read();int y=read();
		int ans=1e18,ad=qd[x]+qd[y];
		for(auto i:v[x]) for(auto j:v[y]){
			ans=min(ans,f[i.first][j.first]+i.second+j.second);}
		printf("%lld\n",ans+ad);
	}
	return 0;
}
int read(){
	int Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}
