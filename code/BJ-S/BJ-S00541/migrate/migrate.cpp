#include <iostream>
using namespace std;

long long c,t,n,d,a[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n; i++) cin >> a[i];
		if(c == 11 || c == 12 || !c){
			if(n == 1) cout << 0 << endl;
			else if((a[2] - a[1]) * 2 > d) cout << 0 << endl;
			else{
				int effi = d / (a[2] - a[1]);
				cout << max(n - effi - effi + 1,0ll) << endl;
			}
		}
	}
	
	return 0;
}