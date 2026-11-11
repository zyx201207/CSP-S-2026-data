#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010];
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0, sum = 0;
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = 1; j < m; i++){
			for(int k = i + 1; k < n; k++){
				sum = max(a[i] & a[k],sum);
			}
		}
		ans = max(ans,sum);
	}
	cout<<0;
}
