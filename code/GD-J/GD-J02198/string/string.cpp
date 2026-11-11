#include<bits/stdc++.h>
using namespace std;
long long n,a[200020],sum,l;
char c[200020];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i]>>c[i];
	for(int i=1,j=n; i<j;) {
		if(c[i]==c[j]) {
			int x=min(a[i],a[j]);
			a[i]-=x;
			a[j]-=x;
		} else {
			int x=min(a[i],a[j]);
			a[i]-=x;
			a[j]-=x;
			sum+=x;
		}
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<sum;
	return 0;
}
