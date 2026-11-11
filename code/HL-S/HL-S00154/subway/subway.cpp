#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int i = 1;i <= k; i++){
			int x;
			cin >> x;
		}
	}
	for (int i = 1; i <= q; i++){
		int l,r;
		cout << w[l] + w[r]<< "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
