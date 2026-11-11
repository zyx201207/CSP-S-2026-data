#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],s[500100],sum,l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		long long cnt=(i-l)*a[i]-(s[i-1]-s[l-1]);
		while(cnt>m){
			cnt-=(a[i]-a[l]);
			l++;
		}
		sum=max(sum,i-l+1);
	}
	cout<<sum;
	return 0;
} 
