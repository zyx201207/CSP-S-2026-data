#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k[50],s,ma,f;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=m;i++) {
		for(int j=0;j<=32;j++) 
			if((1ll<<j)&a[i]) k[j]++;
	}
	s=0;
	for(int i=0;i<=32;i++) if(k[i]==m) s+=(1<<i);
	ma=max(ma,s);
	for(int i=m+1;i<=n;i++) {
		f++;
		for(int j=0;j<=32;j++)
			if((1ll<<j)&a[i]) k[j]++;
		for(int j=0;j<=32;j++)
			if((1ll<<j)&a[f]) k[j]--;
		s=0;
		for(int j=0;j<=32;j++) if(k[j]==m) s+=(1<<j);
		ma=max(ma,s);
	}
	cout<<ma;
	return 0;
}
