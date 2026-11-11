#include<bits/stdc++.h>
using namespace std;
long long n,ans = 0;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	long long x = 1,y = n;
	while(x<y){
		if(a[x]>=a[y]){
			a[x] -= a[y];
			if(c[x]!=c[y]) ans += a[y];
			y--;
			if(a[x]==0) x++;
		}else if(a[x]<a[y]){
			a[y] -= a[x];
			if(c[x]!=c[y]) ans += a[x];
			x++;
		}
	}
	cout << ans;
	return 0;
}