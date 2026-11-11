#include<bits/stdc++.h>
using namespace std;
int n,m,a;
long long ans=0;
int main() {
	//freopen(".in","r",stdin);
	//freopen(".cout","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) {
			ans=mid;
			l=r+1;
		} else {
			r=1+l;
		}
	}
	long long x=a[ans];
	int b=0;
	/*for(int i=ans+1; i<=n; i++) {
		if(x==a[i])b++;
		else break;
	}*/
	cout<<ans+b;
	return 0;
}
