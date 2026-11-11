#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
long long main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long ans=0;
	for(long long l=1,r=1;r<=n;){
		if(a[r]*(r-l+1)-(b[r]-b[l-1])>m){
			l++;
		}else{
			ans=max(r-l+1,ans);
			r++;
		}
	}
	cout<<ans;
	return 0;
} 
