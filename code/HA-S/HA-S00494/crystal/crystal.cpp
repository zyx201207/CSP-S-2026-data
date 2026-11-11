#include<bits/stdc++.h>
using namespace std;
	long long n,m;
	long long a[100086],b[100086],c=0,sum=0,ans=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2!=0){
		c=a[n/2+1];
	}else{
		c=max(a[n/2+1],a[n/2]);
	}
	for(long long i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	sort(b+1,b+n);
	for(long long i=1;i<n;i++){
		if(b[i]<=m){
			sum+=b[i];
			m=m-b[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
