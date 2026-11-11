#include <bits/stdc++.h>
using namespace std;
long long a[2005],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <=n;i++){
		cin >> a[i];
	}
	
	long long max = 0;
	if (m == 2){
	
	for(int i = 1;i <= n;i++){
		for (int j = i+1;j <= n;j++){
			long long g = a[i] & a[j];
			if (g > max)
			max = g;
		}
	}}
	if (m == 1){
		cout << a[n];
		return 0;
	}
	if (m == n){
		max = a[1];
		for (int i = 2;i <= n;i++)
		max = max & a[i];
	}
	cout << max;
	return 0;
}
