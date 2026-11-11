#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
int cnt[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int x=1; x<=n; x++) {
		for(int i=x; i<=n; i++) {
			c[i]=a[i];
		}
		for(int i=x; i<=n; i++) {
			for(int j=1; j<=i-1; j++) {
				if(c[i]==c[j]) {
					for(int k=i; k<=n; k++) {
						c[k]=0;
					}
				}
			}
		}
		for(int i=1; i<=n; i++) {
			cnt[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
