#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int sum = 0;
	for (int i = 1;i <= m;i++){
		int a;
		cin >> a;
		sum += a;
	}
	for (int i = 1;i <= q;i++){
		cout << sum/i << endl;
	}
} 
