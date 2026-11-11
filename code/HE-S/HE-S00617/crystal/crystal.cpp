#include<bits/stdc++.h>
using namespace std;
long long n,m,p=0,sum=0,n1=0,j=1;
long long a[1000005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		p+=a[i];
	}
	n1=n;
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		if(a[i]>=p/n+3){
			n1--;
		}
		}
		for(long long i=1;i<=n;i++){
			if(a[i]<=p/n-10){
			j++;
		}
		}
	for(long long i=j;i<=n1;i++){
		if(a[i]+m>=a[n1]){
			sum++;
			m=a[i]+m-a[n1];
		}
	}
	cout<<sum;
	return 0;
}

