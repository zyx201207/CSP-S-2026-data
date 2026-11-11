#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		for (int j=1;j<=i;j++){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout << maxn-3;
	return 0;
} 
