#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005];
long long x(int y){
	long long nn=-1,b[50005],mm=m;
	for(long long i=1;i<=n;i++){
		if(a[y]<a[i]){
			b[i]=a[y]-a[i];
		}else{
			b[i]=m+1;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(b[i]>b[j]){
				long long q=b[i];
				b[i]=b[j];
				b[j]=q;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		if(mm-b[i]>=0){
			nn++;
		}
	}
	return nn;
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(a[i]>a[j]){
			   long long t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int maxx=-1;
	for(long long i=1;i<=n;i++){
		long long xx=x(i);
		if(xx>maxx){
			maxx=xx;
		}
	}
	cout<<maxx;
	return 0;
}
