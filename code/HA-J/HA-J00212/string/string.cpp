#include<bits/stdc++.h>
using namespace std;

long long ans=0, x=0, y=0;
int n, a[200001], l=1, r=0;
char c[200001];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	r=n;
	while (l<=r) {
		x=1ll*a[l], y=1ll*a[r];
		if (x==y) {
			if (c[l]!=c[r])
				ans+=y;
			l++, r--;
		}
		else if (x>y) {
			if (c[l]!=c[r])
				ans+=y;
			a[l]-=a[r];
				r--;
		}
		else if (y>x) {
			if (c[l]!=c[r])
				ans+=x;
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}

