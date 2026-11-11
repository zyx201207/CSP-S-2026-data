#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m;
long long ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
	cin>>a[i];
	//if(a[i]==511) cout<<2<<"\n";
}
	sort(a+1,a+n+1);
	if(a[n]!=a[n-1]+1&&a[n]!=a[n-1])ans=a[n];
	else if(a[n]==a[n-m]) ans=a[n];
	else ans=a[n-1];
	for(int i=n-1; i>n-m; i--) {
		//	cout<<ans<<"\n"<<a[i]<<"\n";
		//if(ans!=a[i]+1)
		ans=ans&a[i];
	}
	cout<<ans;
}
