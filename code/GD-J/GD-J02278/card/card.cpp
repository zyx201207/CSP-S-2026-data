#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,m,cds[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> cds[i];
	cout << n << " " << m - n << " " << m;
	return 0;
}
