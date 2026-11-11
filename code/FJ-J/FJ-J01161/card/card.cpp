#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
long long n,m,t;
long long a[N],b[N],c,d[N],s;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		b[i]=a[i];
		c=a[i];
		t++;
		for(int j=1; j<=t-1; j++) {
			if(a[i]==b[j]) {
				for(int k=j; k<=i-1; k++) {
					a[k]=0;
					s=i;
				}
			}
		}
		for(int j=1; j<=i; j++) {
			if(a[j]!=0) {
				d[a[j]]++;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		if(d[i]!=0) {
			cout<<d[i]<<" ";
		}
	}
	return 0;
}
