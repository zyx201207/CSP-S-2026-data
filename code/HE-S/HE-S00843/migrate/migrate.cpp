#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
ll a[25];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migeate.out","w",stdout);
	cin>>c>>t; 
	for (int i=1;i<=c;i++) {
		cin>>a[i];
	}
	if (a[2]-a[1]>=t) cout<<c-1;
	else cout<<0;
	return 0;
} 
