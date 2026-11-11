#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,w[500002],k,x,y,cnt[500002] = {0},e,u,a[500002] = {0},t[500002] = {0},s = 0;
	bool f[500002] = {0};
	cin>> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k;
		s = max(s,k);
		for(int j = 1;j <= k;j++){
			cin >> e >> u;
			if(a[e] == 0){
				a[e] = u;
				cnt[e] = 1;
			}else if(a[e] < u){
				t[e] = u;
				f[e]++;
			}else if(a[e] > u){
				t[e] = a[e];
				a[e] = u;
				cnt[e] = 2;
			}
		}
	}
	for(int i = 0;i < q;i++){
		cin >> x >> y;
		for(int i = 1;i <= s + 1;i++){
			if((cnt[i] == 1) && (i != x) && (i != y) && (f[i] == 0)){
				a[i] = 0;
			}
		}
		int sum = w[x] + w[y];
		for(int i = x;i <= y;i++){
			if(i == x){
				sum += a[i];
			}else if(i == y && t[i] != 0){
				sum += t[i];
			}else{
				sum += t[i];
				sum += a[i];
			}
		}
		cout << sum << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
