#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const long long inf=1e18;
int T=1;
int c,n,m,d,q,w[N],a[N][N];
long long f[N][N];
struct node{
	int a,t;
};
vector<node>s[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i(1);i<=m;++i){
		cin>>w[i];
		for(int j(1);j<=m;++j){
			f[i][j]=inf;
		}
	}
	for(int i(1);i<=n;++i){
		int k;
		cin>>k;
		s[i].push_back({k,0});
		int x,y;
		for(int j(1);j<=2*k;++j){
			if(j%2==1) cin>>x;
			else cin>>y;
			if(j%2==0){
				s[i].push_back({x,y});
			}
		}
	} 
	for(int xl(1);xl<=n;++xl){
		int len=s[xl][0].a;
		for(int i(1);i<len;++i){
			for(int j(i+1);j<=len;++j){
				int x=s[xl][i].a,y=s[xl][j].a;
				f[x][y]=min(f[x][y],(long long)s[xl][i].t+s[xl][j].t);
				f[y][x]=min(f[y][x],(long long)s[xl][i].t+s[xl][j].t);
			}
		}
	}
	for(int k(1);k<=m;++k){
		for(int i(1);i<=m;++i){
			for(int j(1);j<=m;++j){
				if(i==j) continue;
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
