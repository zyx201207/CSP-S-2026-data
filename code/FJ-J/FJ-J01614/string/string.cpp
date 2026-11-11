#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
int n,ii,jj;
ll a[N],cnt;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int x;
	for (int i = 1;i<=n;i++){
		cin >> x >> c[i];
		a[i]=a[i-1]+x;
	}
	ii=1;
	jj=n;
	for (ll i = 1;i<=a[n]/2;i++){
		if (a[n]-i+1<a[jj-1]+1)
			jj--;
		if (i>a[ii])
			ii++;
		if (c[ii]!=c[jj])
		    cnt++;
	}
	cout << cnt;
	return 0;
}

