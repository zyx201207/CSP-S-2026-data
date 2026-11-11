#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[1];
	return 0;
}
