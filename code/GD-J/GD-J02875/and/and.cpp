#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int maxn = a[1];
	if(m == 1){
		cout << a[n];
		return 0;
	}
	if(m == n){
		for(int i = 1;i <= n;i++){
			maxn &= a[i];
		}
		cout << maxn;
		return 0;
	}
	if(a[1] == a[n]){
		cout << a[1];
		return 0;
	}
	cout << a[1]
	return 0;
}
