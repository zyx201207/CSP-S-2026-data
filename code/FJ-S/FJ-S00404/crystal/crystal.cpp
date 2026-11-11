#include <bits/stdc++.h>
using namespace std;

long long a[500010];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	double s = 0;
	long long m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> a[i];s += a[i];
	}
	s /= n;
	
	int t = a[0];
	for(int i = 0; i < n; ++i){
		if(abs(s - a[i]) <= abs(s - t))t = a[i];
	}
	
	sort(a, a+n);
	int k=n-1;
	while(a[k] != t)--k;
	
	int ans = 0;
	while(k >= 0){
		
		if(m-a[k] >= 0){
			m-=abs(a[k] - t);
			++ans;
		}
		else break;
		--k;
		
	}
	
	cout << ans << endl;
	
	return 0;
	
}
