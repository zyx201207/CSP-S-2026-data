#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000005], b[100005];
int maxn = 0;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	if(m == 1) {
		for(int i = 0; i < n; i++) {
			maxn = max(maxn, a[i]); 
		} 
		cout<<maxn<<endl;
		return 0;
	}
	if(m == 2) {
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				maxn = max(maxn, (int)(a[i] and a[j]));
			}
		}
		cout<<maxn;
	}
	fclose(stdin); fclose(stdout);
	return 0;
} 
