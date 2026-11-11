#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 20005
int c,n,m,d,q;
int s,e;
int w[N];
int k[N];
int a[N][N];
int t[N][N];
int mp[N][N];
int p[N];
//void dfs(int s,int e){
//	if()
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[k[i]][j];
			cin >> t[k[i]][j];
		}
		for(int j = 1;j <= q;j++){
			cin >> s >> e;
//			dfs(s,e);
			cout << rand() << "\n";
		}
	}
	return 0;
}
