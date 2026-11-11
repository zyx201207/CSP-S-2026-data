#include<bits/stdc++.h>
using namespace std;
long long n,m,absa,mina=1e9,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		absa+=a[i];
	}
	sort(a+1,a+n+1);
	absa/=n;
	for(long long i=1;i<=n;i++){
		if(a[i]<absa){
			sum++;
		}
	}
	for(long long j=1;j<=sum;j++){
		for(long long i=1;i<=sum;i++){
			if(a[i]<absa&&absa-a[i]<mina&&m-(absa-a[i])>=0){
				m-=(absa-a[i]);
				mina=absa-a[i];
				a[i]=absa;
			}
		}	
	}
	long long maxa1=1;
	for(long long i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			maxa1++;
		}
	}
	absa++;	
	for(int k=1;;k++){		
		mina=1e9;		
		for(long long i=1;i<=n;i++){
			if(a[i]<absa){
				sum++;
			}
		}
		for(long long j=1;j<=sum;j++){
			for(long long i=1;i<=sum;i++){
				if(a[i]<absa&&absa-a[i]<mina&&m-(absa-a[i])>=0){
					m-=(absa-a[i]);
					mina=absa-a[i];
					a[i]=absa;
				}
			}	
		}
		long long maxa2=1;
		for(long long i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				maxa2++;
			}
		}
		if(maxa2>maxa1){
			maxa1=maxa2;
		}
		if(m<=0){
			break;
		}
	}
	cout<<maxa1;
	return 0;
}
