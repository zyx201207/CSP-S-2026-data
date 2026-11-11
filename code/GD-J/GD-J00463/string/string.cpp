#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5;
ll n,a[N+10],c[N+10],ans;
char b[N+10];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>b[i];
		c[i]=a[i];
	} 
	for(int i=1,j=n;i<j;) {
		if(c[i]==c[j]) {
			if(b[i]!=b[j]) ans+=c[i];
			c[i]=0,c[j]=0,i++,j--;
		}
		else if(c[i]>c[j]) {
			if(b[i]!=b[j]) ans+=c[j];
			c[i]-=c[j],c[j]=0,j--;
		}
		else {
			if(b[i]!=b[j]) ans+=c[i];
			c[j]-=c[i],c[i]=0,i++;
		}
	}
	cout<<ans;

	return 0; 
}
