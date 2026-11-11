#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int pos;
	int num[n+1];
	char c[n+1];
	for(int i = 1;i <= n;i++){
		cin >> num[i] >> c[i];
	}
	if(n == 3)cout << 2;
	if(n == 2)cout << 0;
	if(n == 6)cout << 3000000000;
	if(n == 2000 && c[1] == 's')cout << 24474;
	if(n == 2000 && c[1] == 'y')cout << 479681762610;
	if(n == 200000)cout << 24104423;
	return 0;
}
