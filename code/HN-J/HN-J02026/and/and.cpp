#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
map<int, int> mp;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(n == m){
		int ans;
		cin >> ans;
		for(int i = 2;i <= n;i ++){
			int x;cin >> x;
			ans &= x;
		}
		cout << ans;
		return 0;
	}
	int l;
	for(int i = 1;i <= n;i ++){
		int x;cin >> x;
		if(mp[x]){continue;}
		mp[x] = 1;
		a[++l] = x;
	}
	sort(a+1, a+l+1, cmp);
	cout << a[m];
	return 0;
}
