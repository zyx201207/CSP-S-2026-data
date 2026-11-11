#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

#define LL long long
#define PLL pair<LL,LL>

const int N=5e5+5;
const int M=5e2+3;

LL c,n,m,d,t,q,ans,inf=2e18;
LL w[N],A[M][M],B[M][M];
vector<PLL> E[N];
bool bl[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	unsigned LL rp=-1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t;
		LL x,y;
		while(t--){
			cin>>x>>y;
			E[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			B[i][j]=inf;
		}
		B[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto u:E[i]){
			for(auto v:E[i]){
				B[u.first][v.first]=min(B[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			A[i][j]=A[j][i];
		}
		for(int j=i;j<=n;j++){
			A[i][j]=inf;bl[j]=0;
		}
		A[i][i]=0;
		while(true){
			LL mp=inf,id=0;
			for(int j=i;j<=n;j++){
				if((!bl[j])&&mp>A[i][j]){
					mp=A[i][j];id=j;
				}
			}
			if(id==0)break;
			bl[id]=1;
			for(int j=i+1;j<=n;j++){
				if(A[i][j]>A[i][id]+B[id][j]){
					A[i][j]=A[i][id]+B[id][j];
				}
			}
		}
	}
	while(q--){
		LL x,y;
		cin>>x>>y;
		ans=inf;
		for(auto u:E[x]){
			for(auto v:E[y]){
				ans=min(ans,A[u.first][v.first]+u.second+v.second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
