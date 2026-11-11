#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long n, ans = 0;
	cin >> n;
	if(n == 1){
		cout << "0";
		return 0;
	}	 
	if(n == 2){
		unsigned long long a1, a2;
		char b1, b2;
		cin >> a1 >> b1;
		cin >> a2 >> b2;
		if(b1 == b2){
			cout << "0";
			return 0;
		}
	}
	for(unsigned long long i = 1; i <= n; i++){
		unsigned long long a;
		char b;
		cin >> a >> b;
		ans += a;
	}
	cout << ans / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
