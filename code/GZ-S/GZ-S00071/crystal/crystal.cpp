//GZ-S00071 黔西市第二中学 熊宇晨
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000005];
int main(){
	freopen("crystal.in","r","stdcin");
	freopen("crystal.out","w","stdcout");
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	long long num=1;
	long long him=0;
	if(n%2!=0){
		him=a[n/2+1];
		long long ans=0;
		for(long long i=n/2+2;i<=n;i++){
			if(him==a[i]){
				num++;
			}
		}
		for(long long i=1;i<=n/2;i++){
		    ans+=(him-a[i]);
			if(ans==m){
				cout<<i+num;
				return 0;
			}else if(ans>m){
				cout<<i+num;
		    	return 0;
			}		
		}
	}else{
		him=a[n/2+1];
		long long ans=0;
		for(long long i=n/2+2;i<=n;i++){
			if(him==a[i]){
				num++;
			}
		}
		for(long long i=1;i<=n/2;i++){
		    ans+=(him-a[i]);
			if(ans==m){
				cout<<i+num;
				return 0;
			}else if(ans>m){
				cout<<i+num;
		    	return 0;
			}		
		}
	}
	return 0;
} 
