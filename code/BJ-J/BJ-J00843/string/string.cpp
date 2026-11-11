#include <bits/stdc++.h>
using namespace std;

int n;
int a[200100];
char c[200100];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	long long l=1, r=0;
	int i=1, j=n;
	for(int i=1;i<=n;++i) {
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	long long ans=0;
	while(l<r && i<j) {
		l+=a[i];
		while(a[i]>0) {
			if(a[j]<a[i]) {
				if(c[j]!=c[i]) ans+=a[j];
				r=r-a[j]+1;
				a[i]-=a[j];
				j--;
			} else {
				if(c[j]!=c[i]) ans+=a[i];
				r=r-a[i]+1;
				a[j]-=a[i];
				a[i]=0;
			}
		}
		i++;
	}
	cout<<ans;
	return 0;
}
