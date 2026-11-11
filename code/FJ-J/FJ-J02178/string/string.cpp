#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
unsigned long long sum;
char c[200005];
signed main() {
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	for(; i<j;) {
		if(c[i]!=c[j]) {
			if(a[i]>a[j]) {
				sum+=a[j];
				a[i]-=a[j];
				j--;
			} else if(a[i]<a[j]) {
				sum+=a[i];
				a[j]-=a[i];
				i++;
			} else {
				sum+=a[i];
				i++;
				j--;
			}
		}
		else
		{
			if(a[i]>a[j]) {
				a[i]-=a[j];
				j--;
			} else if(a[i]<a[j]) {
				a[j]-=a[i];
				i++;
			} else {
				i++;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}


