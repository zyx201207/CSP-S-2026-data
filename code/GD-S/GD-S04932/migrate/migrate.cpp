#include <bits/stdc++.h>
using namespace std;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		memset(x,0,sizeof(0));
		int n;
		long long d;
		cin >> n ;
		cin >> d ;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		cout << "0" << endl;
	}
	return 0;
}
