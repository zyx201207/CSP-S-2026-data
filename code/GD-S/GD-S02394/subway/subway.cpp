#include<iostream>
#include<algorithm> 
#include<vector>
#include<cstring>
using namespace std;
#define int long long
const int MAXN=600,MAXM=5e5+100; 
int n,m,d,q;
int w[MAXM],sk[MAXN];
int e[MAXN][MAXN],dis[MAXN][MAXN];
struct sta{
	int line,t;
};
vector<sta> s[MAXM]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>sk[i];
		for(int j=1,a,t;j<=sk[i];j++){
			cin>>a>>t;
			s[a].push_back({i,t});
		}
	}
	memset(e,0x3f,sizeof(e));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(sta j:s[i])
			for(sta k:s[i]){
				if(j.line==k.line) continue;
				e[j.line][k.line]=min(e[j.line][k.line],j.t+k.t);
				e[k.line][j.line]=min(e[k.line][j.line],j.t+k.t);
			}
	}
	for(int i=1;i<=n;i++)
		e[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<e[i][j]<<' ';
//		cout<<'\n';
//	}
	
	while(q--){
		int x,y,res=(1ll<<60);
		cin>>x>>y;
		//res=;
		for(sta j:s[x])
			for(sta k:s[y])
				res=min(res,j.t+k.t+e[j.line][k.line]);
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
} 
