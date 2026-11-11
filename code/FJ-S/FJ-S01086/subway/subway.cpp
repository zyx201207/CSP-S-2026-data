#include <bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
int c,n,m,d,q,w[500005],k[5005],l[505];
vector<int> a[505],t[505];

ll dis[505][505];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ll u=dis[i][k],v=dis[k][j];
				int f=0;
				for(auto it:a[l[i]]){
					if(it==j){
						f=1;
						continue;
					}
				}
				if(!f){
					int cnt=0;
					for(int it=0;it<=a[l[i]].size();it++) if(a[l[i]][it]==k) cnt=it;
					u+=t[l[i]][cnt];
					for(int it=0;it<=a[l[k]].size();it++) if(a[l[k]][it]==j) cnt=it;
					v+=t[l[k]][cnt];
				}
				dis[i][j]=min(dis[i][j],u+v);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i]*2;j+=2){
			int aa,tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			l[aa]=i;
		}
	}
	floyd();
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << dis[x][y]+w[x]+w[y] << endl;
	}
	return 0;
}
