#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+10;
int a[N], b[N];
int n, m;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+1+n);
	
	for(int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	
	int ans = -1;
	for(int i = 1; i <= n; i++){
		int l = i, r = n;
		while(l <= r){
			int mid = l + (r - l) / 2;
			int change = a[mid]*(mid-i+1);
			int now = b[mid] - b[i-1];
			if(change - now <= m){
				ans = max(ans, mid-i+1);
				l = mid + 1;
			}else r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
