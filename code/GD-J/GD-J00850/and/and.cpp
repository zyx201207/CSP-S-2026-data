#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],r;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	r=a[n];
	for(int i=2;i<=m;i++) r&=a[n-i+1];
	cout<<r;
	return 0;
}
