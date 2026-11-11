#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=1,w=0;
	for(long long l=1,r=1;l<=n&&r<=n;){
		ans=max(ans,r-l+1);
		if(r<n&&w+(a[r+1]-a[r])*(r-l+1)<=m){
			w+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		else{
			w-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	return 0;
}
