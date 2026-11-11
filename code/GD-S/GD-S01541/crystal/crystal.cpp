#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],k[500005],x,y,sum,s,j=1,ma=1,t[500005];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) k[i]=a[i]-a[i-1],t[i]=t[i-1]+k[i];
	for(int i=2;i<=n;i++) {
		sum+=k[i]*(i-j);
		while(sum>m) {
			j++;
			sum=sum-(t[i]-t[j-1]);
		}
		ma=max(ma,i-j+1);
	}
	cout<<ma;
	return 0;
}
