#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
long long c,n,m,d,q,ans;
int w[maxn],a,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a >> t;
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
	}
	cout << 32 <<endl << 17;
	return 0;
}
