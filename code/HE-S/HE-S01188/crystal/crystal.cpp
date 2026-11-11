#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("srystal.in","r",stdin);
	freopen("srystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long b=0;
	for(long long i=1;i<n;i++){
		for(long long j=0;j<n;j++){
			if(a[i]<a[j]){
				b=a[j];
				a[j]=a[i];
				a[i]=b;
			}
		}
	}
	long long c=n/2;
	long long d=c;
	for(long long i=0;i<n;i++){
		if(m<=0){
			break;
		}
		if(m-(a[c]-a[c-1])>=0){
			m=m-(a[c]-a[c-1]);
			a[c-1]=a[c];
			c--;
		}
		else{
			break;
		}
	}
	long long sum=0;
	for(long long i=0;i<n;i++){
		if(a[i]==a[d]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
