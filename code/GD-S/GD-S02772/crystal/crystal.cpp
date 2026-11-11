#include<bits/stdc++.h>
using namespace std;
long long a[500000],s[500000];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	long long sum=0;
	long long ans=1,b=0;
	for(long long i=1;i<n;i++){
		sum+=(a[i]-a[i-1])*(i-b);
		while(sum>m){
			sum-=(a[i]-a[b]);
			b++;
		}
		ans=max(ans,i-b+1);
	}
	cout<<ans;
	return 0;
} 
