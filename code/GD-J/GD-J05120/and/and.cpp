#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	cin>>a[i];
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	} 
	else if(m==n){
		sort(a,a+n);
		long long ans=a[n-1];
		for(long long i=0;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		long long ans=0;
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				long long cnt=a[i]&a[j];
				ans=max(cnt,ans);
			}
			
		}
		cout<<ans;
	}
	else {
		sort(a,a+n);
		long long ans=a[n-1];
		m--;
		for(long long i=n-2;i>=0;i--){
			ans&=a[i];
			m--;
			if(m==0)break;
		}
		cout<<ans;
	}
} 
