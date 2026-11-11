#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	cout << c+n+m+d+q+3 << "\n";
	cout << d-m+n;
	return 0;
}
