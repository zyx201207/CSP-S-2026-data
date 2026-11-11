#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int c,n,m,d,q;
const int M=5e5+5;
const int N=505;
int w[M];
ll f[N][N];
vector<pair<int,int>> sub[N];
vector<pair<int,int>> st[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i) {
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));

	for(int i=1; i<=n; ++i) {
		int k;
		cin>>k;
		for(int j=1; j<=k; ++j) {
			int p,q;
			cin>>p>>q;
			pair<int,int> t1,t2;
			t1= {p,q},t2= {i,q};
			sub[i].emplace_back(t1);
			st[p].emplace_back(t2);
		}
	}
	for(int i=1; i<=n; ++i)f[i][i]=0;
	for(int i=1; i<=n; ++i) {
		for(auto j:sub[i]) {
			int x=j.first,dx=j.second;
			for(auto k:st[x]) {
				int y=k.first,dy=k.second;
				f[i][y]=min(f[i][y],(ll)dx+dy);
				f[y][i]=f[i][y];
			}
		}
	}


	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

			}
		}
	}

	while(q--) {
		int x,y;
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(auto i:st[x]) {
			int p=i.first,di=i.second;
			for(auto j:st[y]) {
				int q=j.first,dj=j.second;
				ans=min(ans,(ll)di+f[p][q]+dj);
			}
		}
		cout<<(ll)w[x]+ans+w[y]<<'\n';
		
	}
	return 0;
}

