#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int n;
long long m;
bool flag = 0;
int full(int x){
	long long s = 0;
	for (int i = x;i <= n-1;i++){
		s += (a[i+1]-a[i])*(i-x+1);
		if (m < s) return i-x+1;
	}
	flag = 1;
	return n-x+1;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	long long k = a[2]-a[1];
	bool f = 0;
	for (int i = 3;i <= n;i++){
		if(a[i]-a[i-1] != k){
			f = 1;
			break;
		}
	}if (f == 0){
		for (int i = 1;i <= n;i++){
			if (m < k){
				cout << i;
				return 0;
			}
			k += k*(i+1);
		}
		cout << n;
		return 0;
	}
	int maxn = -1;
	for (int i = 1;i <= n-1;i++){
		int el = full(i);
		if (flag) break;
		maxn = max(maxn,el);
	}
	cout << maxn;
} 
