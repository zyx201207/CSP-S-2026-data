#include <bits/stdc++.h>
using namespace std;
int n,x;
string s,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	if (n <= 1){
		cout << 0 << '\n';
		return 0;
	}
	
	for (int i = 0;i < n;i++){
		cin >> x >> a;
		for (int j = 1;j <= x;j++){
			s += a;
		}
	}
	long long cnt = 0;
	long long l = 0,r = s.size()-1;
	while (l <= r){
		char nx = s[l],ny = s[r];
		if (nx != ny) cnt++;
		l++;
		r--;
	}
	cout << cnt << '\n';
	return 0;	
} 
