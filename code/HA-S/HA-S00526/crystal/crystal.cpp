#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int a[N],b[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int x = 0,ans = 0;
	for(int i = 1;i < n;i++){
		b[i] = a[i+1]-a[i];
		if(b[i] < m && x == 0){
			x = i;
		}
	}
	c[x] = b[x];
	if(c[x] <= m) ans++;
	for(int i = x+1;i < n;i++){
		c[i] = c[i-1] + b[i];
		if(c[i] <= m) ans++;
	}
	cout << ++ans;
	return 0;
}
