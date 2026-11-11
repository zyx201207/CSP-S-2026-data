#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,l,f,d[200005],t,m,k,ans;
char b[200005],c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i]>>b[i],l+=a[i];
	if(l&1) {
		f=(l>>1)+1;
		int i=1;
		for(;; ++i) {
			if(t+a[i]>=f) {
				m=t+a[i]-f;
				a[i]--;
				break;
			}
			t+=a[i];
		}
		t=0;
	}
//	cout<<1;
	f=(l>>1);
	int i=1;
	for(;; ++i) {
		if(t+a[i]>=f) {
			m=t+a[i]-f;
			break;
		}
		t+=a[i];
	}
	d[n-i+1]=m,m=n-i+1;
//	cout<<i<<'\n';
	c[n-i+1]=b[i];
	for(++i,k=1;; ++i,++k) {
		if(m-k==0) {
			break;
		}
		d[m-k]=a[i];
		c[m-k]=b[i];
//		cout<<m-k<<' '<<c[m-k]<<'\n';
	}
//	cout<<1;
	for(int i=1,j=1; i<=n&&j<=n;) {
		while(a[i]==0&&i<=n)++i;
		while(d[j]==0&&j<=n)++j;
		if(j>n||i>n)break;
//		cout<<a[i]<<' '<<d[j]<<' '<<b[i]<<' '<<c[j]<<' '<<i<<' '<<j<<'\n';
		if(b[i]!=c[j]) {
			ans+=min(a[i],d[j]);
		}
		auto tmp=min(a[i],d[j]);
		a[i]-=tmp;
		d[j]-=tmp;
	}
	cout<<ans;
}

