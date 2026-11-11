#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	vector<int> a;
	vector<char> b;
	int n, x;
	long long cnt = 0;
	char y;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	} 
	int l = 0, r = a.size() - 1;
	while(l <= r){
		int minn = min(a[l], a[r]);
		if(b[l] != b[r])cnt += minn;
		a[l]-= minn;
		a[r]-= minn;
		if(a[l] <= 0)l++;
		if(a[r] <= 0)r--;  
	}
	cout << cnt;
	return 0;
}
