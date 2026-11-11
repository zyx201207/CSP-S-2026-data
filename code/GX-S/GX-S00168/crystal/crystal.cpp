#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m,ans=1,um=0,l=0,r=1;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(;l<n,r<n;r++){
		um+=(a[r]-a[r-1])*(r-l);
		while(um>m){
			um-=a[r]-a[l];
			l++;
		}ans=max(ans,r-l+1);
	}cout<<ans;
	return 0;
}
