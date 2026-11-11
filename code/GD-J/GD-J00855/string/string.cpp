#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, k = 0, u, sum = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string s;
	char v;
	for(int j = 1;j <= n;j++){
		cin >> u >> v;
		for(long long i = k;i < k + u;i++){
			s[i] = v;
		}
		k += u;
	}	
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1;i * 2 <= k;i++){
		if(s[i - 1] != s[k - i])sum++;
	}
	cout << sum;
	return 0;
} 
