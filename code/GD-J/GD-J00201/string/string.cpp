#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sum=0,num=1;
	cin>>n;
	ll a[n+1],count=1;
	char b[n+1],mainn[999999];
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(long long j=1;j<=a[i];j++){
			mainn[num]=b[i];
			num++;
		}

	}
	for(ll i=1;i<=num;i++)cout<<mainn[i];
	cout<<endl;
	if(num%2==0){
		for(ll i=1,j=num-1;i<=num/2,j>num/2;i++,j--){
			if(mainn[i]!=mainn[j])sum++;
			cout<<sum<<" ";
		}
		cout<<endl;
	}
	else if(num%2==1){
		for(long long i=1,j=num-1;i<=num/2,j>num/2+1;i++,j--){
			if(mainn[i]!=mainn[j])sum++;
			cout<<sum<<" ";
		}
		cout<<endl;
	}
cout<<sum;
	return 0;
}  

