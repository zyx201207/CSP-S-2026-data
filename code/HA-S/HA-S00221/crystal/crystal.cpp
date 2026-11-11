#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n;
ll m;
ll a[N];
ll d[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	if (m == 0){
		cout << 0;
		return 0;
	}
		
	ll k = a[2] - a[1];
	
	d[1] = 1, d[2] = 3;
	
	for (int i = 3; i <= n; i++){
		d[i] = d[i - 1] + i;
	}
	for (int i = 2; i <= n; i++){
		if (m >= d[i - 1] * k && m < d[i] * k){
			cout << i;
		}
	}
	return 0;
}