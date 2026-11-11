#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int c,n,m,d1,q;
struct e{
	int to,w,o;
};
int w[M],k[N],a[N][M],t[N][M];
long long d[N][N];
vector<e> g[M];
vector<int> l[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	return 0;
}
