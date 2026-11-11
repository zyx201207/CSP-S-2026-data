#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10000001],y;
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	y=a[n];
	for(int i=2;i<=m;i++){
		y=a[n+1-i]&y;
	}
	cout << y;
	return 0;
}
