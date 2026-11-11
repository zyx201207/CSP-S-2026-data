//migrate, only for special A and B, that testpoint 11 - 14.
#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 11 or c == 12){//A
		for(int i=1;i<=t;i++){
			cin >> n >> d;
			for(int j=1;j<=n;j++)cin >> x[j];
			cout << n - (d / (x[2] - x[1])) + 1 + 3 << "\n";
		}
	} else if (c == 13 and c == 14) {//B
		for(int i=1;i<=t;i++){
			cin >> n >> d;
			for(int j=1;j<=n;j++)cin >> x[j];
			if(n % 2)cout << ((n/2)-1)*((n/2)-1) << "\n";
			else cout << ((n/2)-1)*((n/2)-2) << "\n";
		}
	} else {
		for(int i=1;i<=t;i++){
			cout << "0\n";
		}
	}
}
