#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
char c[N];
int p1 = 1;
ll ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int p2 = n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int sum = 0;
	while(p1 < p2){
		if(c[p1] != c[p2]){
			if(a[p1] <= a[p2]){
				a[p2] -= a[p1];
				ans += a[p1];
				a[p1] = 0;
			}
			else if(a[p1] > a[p2]){
				a[p1] -= a[p2];
				ans += a[p2];
				a[p2] = 0;
			}
			if(a[p1] == 0) p1++;
			if(a[p2] == 0) p2--;
		}
		else if(c[p1] == c[p2]){
			if(a[p1] <= a[p2]){
				a[p2] -= a[p1];
				a[p1] = 0;
			}
			else if(a[p1] > a[p2]){
				a[p1] -= a[p2];
				a[p2] = 0;
			}
			if(a[p1] == 0) p1++;
			if(a[p2] == 0) p2--;
		}
	}
	cout << ans;
	return 0;
}

