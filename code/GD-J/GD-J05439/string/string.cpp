#include<bits/stdc++.h>
using namespace std;
int n;
struct node {
	int count;
	char n;
} a[200005];
long long sum,ans;
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].count>>a[i].n;
		sum+=a[i].count;
	}
	int l=1,r=sum,i=1,j=n;
	while(l<=r) {
		if(!a[i].count) i++;
		if(!a[j].count) j--;
		if(a[i].n!=a[j].n) ans++;
		a[i].count--,a[j].count--;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
