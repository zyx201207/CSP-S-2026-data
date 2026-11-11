#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N];
struct node {
	int w[N];
	int c = 1;
}ans[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	int j = 1, sum = a[i], cnt[N];
    	while(sum != 0) {
    		sum /= 2;
    		cnt[j] = sum % 2;
    		j++;
		}
		for(int k = j; k >= 1; k--) {
			ans[i].w[k] = cnt[ans[i].c];
			ans[i].c++;
		}
	}
	
	
	return 0;
}
 
