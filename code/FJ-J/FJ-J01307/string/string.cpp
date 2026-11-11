#include <bits/stdc++.h>
using namespace std;
long long n;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long a;
	char c; 
	long long ans = 0;
	string t = "";
	for (long long i = 1; i <= n; i++){
		cin >> a >> c;
		for(long long j = 1; j <= a; j++){
			t += c;
		}
	} 
	long long nnnn = t.size();
	for (long long i = 0; i < (nnnn+1)/2; i++){
		int j = nnnn - i - 1;
		if(t[i] == t[j]){
			continue;
		}
		ans++;
	}
	cout << ans;

	return 0;
} 
