#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long q=a[1];
		for(long long i=2;i<=n;i++){
			q=(q&a[i]);
		}
		cout<<q;
		return 0;
	}if(m==1){
		long long q=a[1];
		for(long long i=2;i<=n;i++){
			q=max(q,a[i]);
		}
		cout<<q;
		return 0;
	}
	long long ans=0;
	for(long long i=1;i<=n-m;i++){
		long long cnt=a[i];
		for(long long j=i+1;j<=i+m;j++){
			cnt=(cnt&a[j]);
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
