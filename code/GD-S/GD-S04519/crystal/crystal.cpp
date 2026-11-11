#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y){
	return x > y; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);	
	int n;
	cin >> n;
	
	long long m;
	cin >> m;
	
	int a[250003] = {0};
	int s[250003] = {0};

	for (int i=1; i<=n; i++){
		cin >> a[i];
		s[i] = a[i];
	}
	
	sort(a+1, a+n+1, cmp);
	for (int i=1; i<=n; i++){
		s[i] = a[i];
	}
	long long ans = 1;
	
	for (int i=1; i<n; i++){
		if (i != n && a[i] - a[i+1] > m){
			continue;
		}
		if (a[i] == a[i-1])
			continue;
		int t = m;
		long long M = 0;
		for (int j=i+1; j<=n; ){
			if (a[j] != a[i] && t >= 0){
				a[j]++;
				t--;
			}
			else if (t == 0)
				break;
			else
				j++;
		} 
		for (int j=i; j<=n; j++){
			if (a[i] == a[j]){
				M++;
			}
				
			else
				break; 
		}
		ans = max(ans, M);

		for (int j=1; j<=n; j++){
			a[j] = s[j];
		}
	}
	
	cout << ans;
	
	return 0;
} 
