#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	long long a[500001];
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			m+=a[i];
			a[i]=0;
			sum++;
		}
	}
	long long ans=1000001;
	long long d=0;
	for(long long i=1;i<=n;i++){
		long long r=0;
		for(long long j=1;j<=n;j++){
			if(a[j]<ans&&a[j]>d){
				ans=a[j];
			}
		}
		for(long long j=1;j<=n;j++){
			if(a[j]==ans) r++;
		}
		if(m>=sum*(ans-d)){
			m-=sum*(ans-d);
			sum+=r;
			for(long long j=1;j<=n;j++){
				if(a[j]<=ans){
					a[j]=ans;
				}
			}
		}
		else{
			cout<<sum;
			break;
		}
		d=ans;
		ans=100001;
	}
} 
