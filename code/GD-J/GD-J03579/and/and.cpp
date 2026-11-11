#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int a[maxn], num[35];
bool f[maxn], c[maxn]; 
int binary_search(int l, int r, int key){
	int maxmid = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(num[mid] <= key) l = mid + 1, maxmid = max(maxmid, mid);
		else r = mid - 1;
	}
	return maxmid;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i = 1; i <= 29; i++) num[i] = (int)(pow(2, i) - 1);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int res = binary_search(1, n, a[i]);
		if(a[i] == num[res]) f[i] = true;
	}
	sort(a + 1, a + 1 + n);
	if(n == 1){
		cout << a[n];
		return 0;
	}
	int sum = num[29];
	
	for(int i = n; i >= 1; i--){
		if(a[i] == a[i + 1] || a[i] == a[i - 1]){
			m--;
			sum = sum & a[i];
			c[i] = true;
			cout << m << ":" << i << endl;
		}
		else if(f[i]){
			m--;
			sum = sum & a[i];
			c[i] = true;
			cout << m << ":" << i << endl;
		}
		if(m == 0){
			cout << sum;
			return 0;
		}
	}
	for(int i = m; i >= n - m + 1; i--) if(!c[i]) sum = sum & a[i];
	cout << sum;
	return 0;
} 
