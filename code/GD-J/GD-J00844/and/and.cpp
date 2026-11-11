#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	unsigned long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=(n+m-1)/m;
	unsigned long long c[l];
	unsigned long long maxx=0;
	unsigned long long j=0,jj=n-1;
	for(int i=0;i<(l+1)/2;i++){
		c[i]=a[j];
		long long k=0;
		for(k=j+1;k<j+m-2;k++){
			c[i]=(c[i]&a[k]);
		}
		for(k=j+m-1;k<n;k++){
			maxx=max(maxx,(c[i]&a[k]));
		}
		j+=m-1;
		c[l-i-1]=a[jj];
		for(k=jj-1;k>=jj-m+2;k--){
			c[l-i-1]=(c[l-i-1]&a[k]);
		}
		for(k=jj-m+1;k>0;k--){
			maxx=max(maxx,(c[l-i-1]&a[k]));
		}
		jj-=m-1;
		if(j>=jj){
			break;
		}
	}
	cout<<maxx;
	return 0;
}

