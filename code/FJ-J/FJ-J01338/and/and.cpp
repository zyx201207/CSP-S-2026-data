#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],m,q,ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i)cin>>a[i];

	for(int i=1<<30; i>=1; i>>=1) {
		auto t=0;
		for(int j=1; j<=n; ++j) {
			if(i&a[j]) {
				b[++t]=a[j];
			}
		}
		if(t>=m) {
			ans+=i;
			n=t;
			for(int j=1; j<=t; ++j)a[j]=b[j];
		}
	}
	cout<<ans;
}













