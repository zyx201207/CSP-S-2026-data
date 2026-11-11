#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200005];
char t[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n;
	cin>>n;
	LL sum=0;
	for(LL i=1;i<=n;++i) {
		scanf("%lld %c",&a[i],&t[i]);
		sum+=a[i];
	}
	LL tmp=0;
	LL idx=0;
	for(LL i=1;i<=n;++i) {
		tmp+=a[i];
		if(tmp>=(sum+1)/2) {
			idx=i;
			break;
		}
	}
	cout<<tmp<<" "<<idx;
	cout<<endl;
	if(tmp-(sum+1)/2) {
		for(int i=n;i>=idx;--i)
			a[i+1]=a[i],t[i+1]=t[i];
		a[idx+1]=tmp-(sum+1)/2;
		a[idx]=a[idx]-a[idx+1];
	}
	reverse(a+idx+1,a+n+2);
	reverse(t+idx+1,t+n+2);
	for(int i=1;i<=n+1;++i) {
		cout<<a[i]<<" "<<t[i]<<endl;
	}
	return 0;
}

