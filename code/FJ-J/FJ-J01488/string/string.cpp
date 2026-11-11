#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	long long a[n];
	char b[n];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long i=0,j=n-1;
	while(i<=j){
		if(b[i]!=b[j]){
			if(a[i]>a[j]){
				sum+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]==a[j]){
				sum+=a[i];
				i++;
				j--;
			}else{
				sum+=a[i];
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]==a[j]){
				i++;
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}
