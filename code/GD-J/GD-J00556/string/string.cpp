#include <bits/stdc++.h>
using namespace std;
char a[1000000000];
int main(){
	long long n,sum=0;
	long long ans=0; 
	cin>>n;
	for(long i=0;i<n;i++){
		long long k;
		char c;
		cin>>k>>c;
		for(int j=sum;j<sum+k;j++){
			a[j]=c;
		}
		sum+=k;
	}
	for(long i=0;i<sum/2;i++){
		if(a[sum-i-1]!=a[i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
