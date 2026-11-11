#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char b[200005];
long long c[200005];
char d[200005];
unsigned long long alll;
unsigned long long ans;
unsigned long long sum=0;
unsigned long long temp=0;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
		alll+=a[i];
	}

	for(long long i=1; i<=n; i++) {
		if(b[i]!=b[i-1]) {
			sum++;
			d[sum]=b[i];
			c[sum]=a[i];

		} else {
			c[sum]+=a[i];
		}
	}
	if(sum==1) {
		cout<<0;
		return 0;
	}
	long long i=1,j=sum;
	while(ans<alll/2 and j>=i) {
		if(d[i]!=d[j]) {
			if(c[i]>c[j]) {
				ans+=c[j];
				c[i]-=c[j];
				j--;
			} else if(c[i]<c[j]) {
				ans+=c[i];
				c[j]-=c[i];
				i++;
			} else {
				ans+=c[i];
				j--;
				i++;
			}
		} else {
			if(c[i]>c[j]) {
				c[i]-=c[j];
				j--;
			} else if(c[i]<c[j]) {
				c[j]-=c[i];
				i++;
			} else {
				j--;
				i++;
			}
		}
	}
	cout<<ans;




	return 0;
}
