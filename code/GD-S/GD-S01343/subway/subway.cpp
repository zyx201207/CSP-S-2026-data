#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
using ui = unsigned int;
constexpr unsigned int inf = 1<<30;
constexpr unsigned int N = 5e2+1, M =5e5+1;

/*

gard <-|t_1|-> room <-|t_2|-> star

using f[i][j] named the min distance from the room_i to way_j
so easy to see the min time of the plan a -> b is:
 min{f[a][j]+f[b][j]) j in [0,500]
it can have a,b in 1e5 j in [1,500]
we need to pre solve f[i][j] by way
*/

struct dw{
	ui t = inf;
};

vector<array<dw, N>> f;

// O(n^2*m^2) n: dot, m: way
void fdy(int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int u = 0; u<n;u++){
				for(int k=0;k<m;k++){
					f[i][j].t=min(f[i][j].t, f[i][k].t+f[u][k].t+f[u][j].t);
				}
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	io;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	f.resize(M);
	vector<int> ws(m);
	for(int& i:ws){
		cin>>i;
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a;
			cin>>a;
			cin>>f[a][i].t; 
		}
	}
	fdy(m,n);
	for(int i=0;i<q;i++){
		int s,e;
		cin>>s>>e;
		ui ans = inf;
		for(int j=0;j<n;j++){
			ans = min(ans, f[s][j].t+f[e][j].t);
		}
		cout<<ans+ws[s]+ws[e]<<'\n';
	}
	return 0;
}


 
