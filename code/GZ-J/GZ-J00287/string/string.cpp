//ÌïÑåê¿ GZ-J00287
#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;long long a[200005];char c[200005];
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >>c[i];
	long long u = 1,d = n,q;
	while(u != d){
		if(c[u] != c[d]) ans += min(a[u],a[d]);
		q = min(a[u],a[d]);
		a[d] -= q;
		a[u] -= q;
		if(a[u] == 0) u++;
		if(a[d] == 0) d--;
	}
	cout << ans;
	return 0;
 } 
