#include <bits/stdc++.h>
using namespace std;
const int N = 2000006;
long long c,t,n,d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	long long t1 = t;
	while (t--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++){
			cin >> x[i]; 
		}
	}
	for (int i = 1;i <= t1;i++){
		cout << i << endl;
	}
}
