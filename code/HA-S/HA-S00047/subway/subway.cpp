#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<long long,long long>,long long>> mp[3][505];
long long line[505][505];
int main() {
	memset(line,0x3f,sizeof(line));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<long long> station(m);
	for(long long i=0; i<m; i++) {
		cin >> station[i];
		mp[0][i].push_back({{1,i},station[i]});
		mp[1][i].push_back({{0,i},station[i]});
		line[i][i]=0;
	}
	for(long long i=0; i<n; i++) {
		long long t;
		cin >> t;
		vector<long long> u(t),v(t);
		long long k=0;
		for(long long j =0; j<t; j++) {
			cin >> u[j] >> v[j];
			u[j]--;

			if(u[j]==i) {
				k=v[j];
			} else {
				line[i][u[j]]=v[j];
			}
		}
		for(long long j =0; j<t; j++) {
			if(u[j]!=i) {
				line[i][u[j]]+=k;
			}
		}
	}
	for(long long k=0; k<503; k++)
		for(long long a=0; a<503; a++) {
			for(long long b=0; b<503; b++) {
				line[a][b] = min(line[a][b],line[k][a]+line[b][k]);
			}
		}
	while(q--) {
		long long u,v;
		cin >> u >> v;
		cout << line[u-1][v-1]+mp[0][u-1][0].second+mp[0][v-1][0].second << endl;
	}
	return 0;
}
