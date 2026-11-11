#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, sum;
int cnt = 1;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		long long a;
		char c;
		cin >> a >> c;
		for(int i = cnt;i < cnt + a;i++){
			s[i] = c;
		}
		cnt = cnt + a;
	}
	for(int i = 1;i <= (cnt - 1) / 2;i++){
		if(s[i] != s[cnt - i]){
			sum++;
		} 
	}
	cout << sum;
	return 0;
} 
