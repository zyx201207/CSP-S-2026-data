#include <bits/stdc++.h>
using namespace std; 
long long sum;
long long mid = 0;
long long q = 1;
char s[200005];
int main(){
	freopen(string.in,'r',stdin);
	freopen(string.out,'w',stdout);
	
	int n;cin >> n;
	
	for (int i = 1;i <= n;i++){
		int a;char c;cin >> a >> c;
		mid += a;
		for (int j = 1;j <= n;j++) s[q++] += c;
	}
	for (int i = 1;i <= ceil(mid/2.0);i++){
		if (s[i] != s[mid - i]){
			sum++;
		} 
	}
	cout << sum << endl;
	return 0;
}
