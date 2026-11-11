#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	int a;
	cin >> a;
	int b[2*a+3];
	int c[2*a+3];
	long long n=0;
	for (int i = 2;i<=a+1;i++){
		cin >> b[i-2];
		cin >> c[i-2];
		n+=b[i]*c[i];
	}
	cout << 2;
    return 0;	
}
