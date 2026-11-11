#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
long long s[500005];
bool check(long long v){
	for(int i=1;i<=n-v;i++){
		if(s[i+v-1]-s[i-1]+m>=a[i+v-1]*v)
			return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	//二分似乎可以过？
	//O(nlogn) 
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	long long l=0,r=n+1,mid;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
		if(check(mid))
			ans=max(ans,mid);
	}
	cout<<ans;
	return 0;
} 
