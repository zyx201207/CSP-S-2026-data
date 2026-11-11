#include<bits/stdc++.h>
using namespace std;
int n, top;
long long cnt, sum;
string tmp;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1, k;i <= n; ++ i){
		char c;
		cin >> k >> c;
		for(int j = 1;j <= k; ++ j) tmp += c;
	}
	long long len = tmp.size();
	for (int i = 0;i < len / 2 + 1; ++ i) if (tmp [ i ] != tmp [ len - i - 1 ]) cnt ++;
	cout << cnt;
	return 0;
} 
