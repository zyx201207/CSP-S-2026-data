#include <bits/stdc++.h>
using namespace std;
const int MAXANS = 4 * 1e6,MAXN = 2 * 1e6 + 5;
int c,t,ans[MAXANS],d,x[MAXN];
void dfs(int l,int r,int step){
	if(l == r) {
		ans[step]++;
	}
	for(int i = 1;i <= min(d,r-l);i++){
		if(x[l + i] - x[l] > d){
			break;
		}
		dfs(l + i,r,step + 1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		int n1;
		cin >> n1 >> d;
		int cnt = 0,n = n1;
		for(int i = 0;i < n1;i++) {
			cin >> x[i];
			if(x[i] - x[i] > d) n = i;
		}
		for(int i = 0;i < n - 2;i++){
			for(int j = i + 2;j < n;j++){
				for(int k = 0;k <= n;k++) ans[k] = 0;
				dfs(i,j,0);
				for(int k = 1;k <= n;k++){
					if(ans[k] != 2 && ans[k] != 0){
						break;
					}else if(ans[k] == 2){
						cnt++;
						break;
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
