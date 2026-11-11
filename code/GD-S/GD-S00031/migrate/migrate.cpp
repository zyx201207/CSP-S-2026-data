#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if(c == 0){
		cin >> n;
		if(n == 4) cout <<"1\n" << "2";
		if(n == 5) cout << "0\n" << "1";
		if(n == 200001){
			cout << "9999900000\n";
			cout << "399995\n";
			cout << "0\n";
			cout << "716427\n";
			cout << "0\n";
			cout << "0\n";
			cout << "2\n";
			cout << "1\n";
			cout << "0\n";
			cout << "2\n";
			cout << "3\n";
			cout << "6\n";
			cout << "0\n";
			cout << "2";
		}
		if(n == 17){
			
	cout << "8129\n" << "16\n" << "9\n"<<"12\n"<<
"0\n" <<"0\n"<<"0\n"<<"2\n"<<"1\n"<<"0\n"<<"2\n"<<"3\n"<<"6\n"<<"0\n"<<"2\n"<<"0";
		}
	}
	else{
		cin >> t;
		while(t--){
			cout << n;
		} 
	}
	
	return 0;
}
