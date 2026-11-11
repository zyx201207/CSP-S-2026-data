#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		long long mx=-1;
		for(long long i=1;i<=n;i++){
			mx=max(a[i],mx);
		}
		cout<<mx;
	}else if(m==n){
		long long sum=a[1];
		for(long long i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
	}else if(m==2){
		long long mx=-1;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
	}else{
		sort(a+1,a+n+1,greater<long long>());
		long long sum=a[1];
		for(long long i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
	return 0;
} 
