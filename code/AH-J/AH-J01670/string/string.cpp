#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char b[200005];
unsigned long long ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<=r) {
		if(b[l]!=b[r]) {
			ans+=min(a[l],a[r]);
		}
		if(a[l]<=a[r]) {
			a[r]-=a[l];
			l++;
		} else {
			a[l]-=a[r];
			r--;
		}
//		cout<<l<<" "<<r<<" "<<ans<<endl;
	}
	cout<<ans;
}
