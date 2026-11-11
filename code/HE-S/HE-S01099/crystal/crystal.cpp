#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],b[10000000],c[10000000],d[1000000],i=0,k=-1,ma=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (long long i=0 ; i<n ; i++)cin>>a[i];
	sort(a,a+n);
	
	for (long long i=0 ; i<n-1 ; i++){
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i];
	}
	d[0]=0;
	for (long long i=1 ; i<n ; i++){
		d[i]=b[i-1]*i+d[i-1];
	}
	
	for ( ; i<n-1 ; i++){
		if (d[i]-c[k]>m){
			k++;
			ma=max(ma,i-k);
		}
	}
	if (k==-1)ma=i;
	cout<<ma;
	return 0;
}
