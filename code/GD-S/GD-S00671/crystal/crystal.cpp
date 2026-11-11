#include<bits/stdc++.h>
using namespace std;
const long long I=5e5+1;
long long a[I];
long long s[I];
long long w[I];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++){
		s[i]=a[i+1]-a[i];
		w[i]=w[i-1]+(s[i]*i);
	}
	long long ans=0;
	long long r=n-1;
	for(long long l=1;l<n;l++){
		for(long long r=n-1;r>l;r--){
			long long as=w[r]-w[l];
			if(as<=m){
				if(r-l+2>ans){
					ans=r-l+2;
				}
			}
		}
	}
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
