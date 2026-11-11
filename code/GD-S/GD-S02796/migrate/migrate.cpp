#include<bits/stdc++.h>
using namespace std;
const int maxn = 2*1e6+10;
int c,t,n,d;
long long x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	int k = 1;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		cout << k << endl;
		k++;
	}
	return 0;
}
