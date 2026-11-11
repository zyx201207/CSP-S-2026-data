#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+5;

int x[N],vis[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		int n,d;
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> x[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				int a=x[i],b=x[j];
				int dis_mi = N;
				queue<int> q;
				q.push(i);
				while (!q.empty){
					int u=q.front();
					int v=x[u];
					q.pop();
					for (int k=1;k<=n;k++){
						if (abs(v-x[k]) <= d && k != i){
							vis[k] = vis[u]+1;
						}
						if (k = j){
							dis_mi = vis[k];
						}
					}
				}
				int pl_ = i;
				for(int q=1;q<=q)
					for (int k=1;k<=n;k++){
						if (abs(v-x[k]) <= d && k != i){
							vis[k] = vis[u]+1;
						}
						if (k = j){
							dis_mi = vis[k];
						}
					}
				}
			}
		}
	}
	return 0;
} 
