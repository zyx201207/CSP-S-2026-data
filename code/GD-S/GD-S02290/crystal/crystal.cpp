#include<bits/stdc++.h>
using namespace std;
const long long N = 500000 + 7;
long long n,m,ans,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i ++){
		b[i] = b[i - 1] + a[i]; 
	}
	int i,maxn = 0,l = n,r = n;
	while(r){
		l = min(l,r);
		while(a[r] * (r - l) - (b[r - 1] - b[l - 1]) <= m && l) l --;
		maxn = max(maxn,(r - l + 1));
		r --;
	}

	cout << maxn - 1;

	return 0;
}
