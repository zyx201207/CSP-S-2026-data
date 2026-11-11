#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[200005];
ll s,t,l,r,new_L,L;
ll ans;
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		cin>>c[i];
	}
	int i=1,j=n;
	l=a[1],r=a[n];
	while(i<j) {
		new_L=min(l,r);
		if(c[i]!=c[j]) {
			ans+=new_L-L;
		}
		if(l==new_L) {
			i++;
			l+=a[i];
		}
		if(r==new_L) {
			j--;
			r+=a[j];
		}
		L=new_L;
	}
	printf("%lld",ans);
	return 0;
}
