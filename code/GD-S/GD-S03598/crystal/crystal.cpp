#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5;
ll n,m,ans,sum,a[N],s[N];
int main() {
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n >>m;
	for (int i=1;i<=n;i++) {
		cin >>a[i];
	}
	sort (a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		s[i]=s[i-1]+a[i];
	}
	for (int i=1,st=1;i<=n;i++) {
		for (;(i-st)*a[i]-(s[i-1]-s[st-1])>m && st<=i;st++);
		ans=max((ll)(i-st+1),ans);
	//	cout <<i <<" " <<st <<" " <<(i-st)*a[i]-(s[i-1]-s[st-1]) <<"\n";
	}
	cout <<ans;
	return 0;
}

