#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+50;
long long x[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	for(;t--;){
		long long n, d, sd;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		sd = x[2]-x[1];
		long long s = d / sd;
		if(s>=2){
			cout << n-s-1<<endl;
		}
		else{
			cout << 0<<endl;
		}
	}
	return 0;
}
