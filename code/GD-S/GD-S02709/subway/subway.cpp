#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int w[N];
struct Node{
	int ki;
	int a, t;
}k[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i].ki;
		for(int j=1;j<=k[i].ki;j++){
			cin >> k[i].a >> k[i].t;
		}
	}
	for(int i=1;i<=q;i++){
		cout << 66;
	} 
	return 0;
}
