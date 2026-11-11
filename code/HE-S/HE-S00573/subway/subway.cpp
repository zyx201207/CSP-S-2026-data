#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10, M=550;
int c, n, m, d, p, a[N], k[N];
int dist[N][M];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_withm_stdio(false);
	cin.tie(0);
	
	memset(dist, 0x3f, sizeof(dist));
	for(int i=0; i<M; i++) dist[i][i]=0;
	
	cin>>c>>n>>m>>d>>p;
	
	return 0;
}
