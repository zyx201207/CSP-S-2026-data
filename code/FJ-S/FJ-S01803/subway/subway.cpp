#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 8;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w;
}
int c,m,n,d,q,W[MAXN],a[MAXN][21],dis[550][550];
vector<int> A[MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();n = read();m = read();d = read();q = read();
	for(int i = 1;i <= m;i++) W[i] = read();
	memset(a,0x3f,sizeof a);
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i <= n;i++){
		int L;L = read();
		for(int j = 1;j <= L;j++){
			int x,y;x = read();y = read();
			a[x][(int)A[x].size()] = y;A[x].push_back(i);
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < A[i].size();j++)
			for(int k = j + 1;k < A[i].size();k++){
				int J = A[i][j],K = A[i][k];
				dis[J][K] = min(dis[J][K],a[i][j] + a[i][k]);
				dis[K][J] = min(dis[K][J],a[i][j] + a[i][k]);
			}
	}
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
//		for(int j = 1;j <= n;j++) cout << dis[i][j] << " ";
//		cout << "\n"; 
	}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);
	while(q--){
		int u,v,ans = dis[0][0];u = read();v = read();
		for(int i = 0;i < A[u].size();i++)
			for(int j = 0;j < A[v].size();j++){
				int ll = A[u][i],rr = A[v][j];
				ans = min(ans,a[u][i] + a[v][j] + dis[ll][rr]);
			}
		cout << ans + W[u] + W[v] << "\n";	 
	}
	return 0;
}

