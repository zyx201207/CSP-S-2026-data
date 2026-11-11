#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ans;
int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int h;
			cin >> h;
		}
	}
	for(int i = 1;i <= q;i++){
		int a;int t;
		cin >> a >> t;
		ans += t;
		cout << ans;
	}
	
	return 0;
}

