#include <bits/stdc++.h>
using namespace std;
int m,n;
long long q[2*100000+5];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> q[i];
	}
	sort(q+1,q+n+1);
	cout << q[1];
	return 0;
}
