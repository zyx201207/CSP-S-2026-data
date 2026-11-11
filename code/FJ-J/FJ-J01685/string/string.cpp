#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x[202202],ans=0;
char a[202202];
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>x[i]>>a[i];
	}
	for(ll i=1; i<=n; i++) {
		if(a[i]!=a[n-i+1]) {
			if(x[i]>=x[n-i+1]) {
				ans+=x[n-i+1];
				a[n-i+1]=a[i];
			} else {
				ans+=x[i];
				x[n-i]=x[n-1]+x[n-i+1]-x[i];
			}

		}
	}
	cout<<ans;
	return 0;
}
