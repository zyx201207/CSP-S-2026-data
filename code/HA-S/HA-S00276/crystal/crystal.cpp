#include<bits/stdc++.h>
using namespace std;
long long a[int(5e5)+10];
long long sum2[int(5e5)+10],sum1[int(5e5)+10];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	sum1[0]=0;
	for(int i=1;i<n;i++){
		sum1[i]=sum1[i-1]+(a[i]-a[i-1])*i;
	}
	sum2[n-1]=0;
	for(int i=n-2;i>=0;i--){
		sum2[i]=sum2[i+1]+(a[n-1]-a[i]);
	}
	for(int i=n-1;i>=0;i--){
		if(m>=sum1[i]){
			ans=ans>i?ans:i+1;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(m>=sum2[i]){
			ans=ans>n-i?ans:n-i;
			break;
		}
	}
	cout<<ans;
	return 0;
}
