#include<bits/stdc++.h>
using namespace std;
long long a[514514];
long long s[514514];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	} 
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if((mid*a[i])-(s[i]-s[i-mid])<=m){
				ans=max(ans,mid);
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
	}
	cout<<ans;
} 
//600B    600B
