#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
char b[N];
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , sum = 0;
	cin >> n;
	while(n--){
		int a;
		char c;
		cin >> a;
		cin >> c;
		sum += a;
		for(int i = sum - a ; i < sum ; i++){
			b[i] = c;
		}
	}
	int ans = 0;
	for(int i = 0 , j = sum-1 ; i <= j && j >= i ; ){
		if(b[i] != b[j]) ans++;
		//cout << b[i] << " " << b[j] << endl;
		i++;
		j--;
	}
	cout << ans;
	return 0;
} 
