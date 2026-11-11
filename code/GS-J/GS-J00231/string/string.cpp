#include<bits/stdc++.h>
using namespace std;
string as[20000];
long long a[400];
string b[400];
int n;
long long m=10000;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ans=0;
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i]; 
	
		for(long long i=0;i<a[i];i++){
			for(long long j=0;j<=n;j++){
				as[i]=b[i];
			
			}
		
		}	
	}
	for(long long i=1;i<=500;i++){
		for(long long j=500;j>=0;j--){
			if(as[1-i]==as[i-m]){
				ans=0;
			}
			else {
				ans=ans+1;
			}
		}
	
	}
	cout<<ans;
	return 0;
}
