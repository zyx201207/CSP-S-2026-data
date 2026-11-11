#include<bits/stdc++.h>
using namespace std;
string s1;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin >> x >> a;
		for(int i=1;i<=x;i++){
			s1 += a;
		}
	}
	int cnt = 0;
	for(int i=0;i<(int)s1.size()/2;i++){
		if(s1[i] != s1[(int)s1.size()-i-1]){
			cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
