#include <bits/stdc++.h>
using namespace std;
#define ll long long
int l,ans;
char a[100000005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	int yb=1,js;
	for(int i=1;i<=l;i++){
		int n;
		char m;
		cin>>n>>m;
		js=yb+n;
		for(;yb<js;yb++) a[yb]=m;
	}
	for(int i=1;i<=yb/2;i++) if(a[i]!=a[yb-i]) ans++,a[i]=a[yb-i];
	cout<<ans;
	return 0;
}
