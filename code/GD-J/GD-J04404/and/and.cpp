#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==1) {
		int ans=-1;
		for(int i=1; i<=n; i++) {
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	if(m==2) {
		int ans=-1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i!=j) {
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	if(m==3) {
		int ans=-1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					if(i!=j&&i!=k&&j!=k) {
						ans=max(ans,(a[i]&a[j]&a[k]));
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	if(m==4) {
		int ans=-1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					for(int l=1; l<=n; l++) {
						if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l) {
							ans=max(ans,(a[i]&a[j]&a[k]&a[l]));
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	if(m==n) {
		int ans=a[1];
		for(int i=2; i<=n; i++) {
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	return 0;
}
