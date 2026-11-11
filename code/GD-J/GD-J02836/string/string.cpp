#include<iostream>
using namespace std;
long long n;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if(n == 1) cout << 0;
	else{
		cout << n - 1;
	}
	return 0;
}
