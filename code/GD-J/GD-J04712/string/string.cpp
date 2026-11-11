#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	int b = 1;
	long long a;
	char c;
	char sum[1000000] = {};
	cin >> n;
	int ans = 0;
	if(n == 1){
		cout << 0;
	}
	for(int i = 1; i <= n; i ++){
		cin >> a >> c;
		for(int j = 1; j <= a; j ++){
			sum[b] = c;
			b ++;
		}
	}
	for (int i = 1; i <= b / 2; i ++){
		if(sum[i] != sum[b - i]){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
