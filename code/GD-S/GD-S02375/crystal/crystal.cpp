#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, a[500005], pre[500005], cnt=1, minx=1e7, minpre;
	cin >> n >> m;
	a[0] = 0;
	int t = 0;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		t += a[i];	
	}
	t /= n;
	
	int l=1, r=n;
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		pre[i] = abs(t-a[i]);
		if(minx>=pre[i]){
			minx = pre[i];
			minpre = i;
		}
	}
	for(int i=1; i<minpre; i++){
		if(m>=a[minpre]-a[i]){
			m -= a[minpre]-a[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
