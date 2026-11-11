//GZ-J00600 贵阳华师一学校 蒋金珂
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001],b[200001];
char c[200001];
int main() {
freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];

	}
	long long l=1,r=b[n],idl,idr,ans=0,step;
	while(l<r) {
		idl=lower_bound(b+1,b+n+1,l)-b;
		idr=lower_bound(b+1,b+n+1,r)-b;
		step=min(b[idl]-l+1,r-b[idr-1]);
		l+=step;
		r-=step;
		if(c[idl]!=c[idr]) {
			ans+=step;
		}
	}
	cout<<ans;
}

