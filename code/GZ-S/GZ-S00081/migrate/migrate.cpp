//GZ-S00081 六盘水市第二十四中学 周启明 
#include <bits/stdc++.h>
using namespace std;

int c;
long long t,n,d,a;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int z = 1;z <= t;z++){
		cin >> n >> d;
		vector<long long> x;
		x.push_back(0);
		for (int i = 1;i <= n;i++){
			cin >> a;
			x.push_back(a);
		}
		cout << z << "\n";
	}
	return 0;
}

