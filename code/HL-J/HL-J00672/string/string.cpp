#include<bits/stdc++.h>
using namespace std;
int a[200000];
char b[200000];
char  c[200000000];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0,ans=0;
	long long cnt=0;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		cin>>b[i];

	}
		for(int i=0; i<n; i++)
		{
			cnt+=a[i];
		}


for(int i=0; i<=n; i++) {
	for(int j=k; j<k+a[i]; j++) {
		c[j]+=b[i];
	}
	k+=a[i];
}

	for(int i=0; i<=cnt/2; i++) {
	     if(c[i]!=c[cnt-i])
	     {
	     	ans++;
		 }
		
	}
cout<<ans;
}
