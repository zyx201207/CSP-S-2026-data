#include<bits/stdc++.h>
using namespace std;
int a[200005],ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n; i>abs(n-m); i--) {
		if(ans==0) {
			ans=a[i];
		}
		ans=(ans&a[i]);

	}
	cout<<ans;
	return 0;
}
/*4 2
3 15 12 12*/



