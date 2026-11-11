#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int c,t,ans,n,d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>d;
		for(int j=1; j<=n; j++) {
			cin>>a[N];
		}
		if(n=1&&n==5) {
			cout<<0;
		} else {

			int u=0,sum=0;
			for(int j=1; j<=n; j++) {
				for(int i=j; i<=n; i++) {
					if(a[i]+d<a[i+1])u=i+1;
				}
				for(int q=u; q>=j; q--) {
					if(a[q]-d<=a[q-1])sum++;
				}
				if(sum==2) ans++;
			}
			cout<<ans;
		}
	}
	return 0;
}
