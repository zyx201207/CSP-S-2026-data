#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5+10;
int w[N],a[N],t[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ret = 0;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[j] >> t >> [j];
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
	}
	return 0;
}
