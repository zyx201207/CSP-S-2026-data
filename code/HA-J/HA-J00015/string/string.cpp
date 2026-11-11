#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
char c[maxn];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	long long ans=0;
	while(i<=j) {
		int x=min(a[i],a[j]);
		if(c[i]!=c[j]) {
			ans+=x;
			a[i]-=x;
			a[j]-=x;
		} else {
			a[i]-=x;
			a[j]-=x;
		}
		if(a[i]<=0) {
			i++;
		}
		if(a[j]<=0) {
			j--;
		}
	}
	cout<<ans;
	return 0;
}
