#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e6+5;
int x[N];int n,d;
int f(int u,int v){
	int s=ceil(ceil(x[v]-x[u])/d);
	int cnt=0;
	for (int i=u+1;i<=v-1;i++){
		for (int j=i;j<=v-1;j++){
			
		}
	}
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >>c>>t;
	while(t--){
		cin >>n>>d;
		int ans=0;
		for (int i=1;i<=n;i++){
			cin >>x[i];
		}for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (f(i,j)==2){
					ans++;
				}
			}
		}cout <<ans<<endl;
	}
	return 0;
}

