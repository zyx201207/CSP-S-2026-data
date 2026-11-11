#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=200005;
int n,len,l,r,al;
//int p=0,q=0;
int ans=0;
int a[N];
char c[N];

signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	len=n/2;
	l=1;
	r=n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		al+=a[i];
	}
	int ans=0; 
	while(l<r) {
		if(c[l]!=c[r]) {
			if(a[l]>a[r]) {
				ans+=a[r];
			}else if(a[l]<a[r]) {
				ans+=a[l];
			}else {
				ans+=a[r];
			}
		}
		if(a[l]>a[r]) {
//			p+=a[r];
//			q+=a[r];
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]) {
//			p+=a[l];
//			q+=a[l];
			a[r]-=a[l];
			l++;
		}else {
//			p+=a[r];
//			q+=a[r];
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
