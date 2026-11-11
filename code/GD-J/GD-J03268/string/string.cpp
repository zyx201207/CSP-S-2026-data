#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x;
	string y;
}a[200005], b[200005], c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, m;
	long long sum = 0, ans = 0;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y;
		for(int j = 1; j <= a[i].x; j++){
			s += a[i].y;
		}
		sum += a[i].x;
	}
	for(int i = 0; i <= sum/2-1; i++){
		if(s[i] != s[sum-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
