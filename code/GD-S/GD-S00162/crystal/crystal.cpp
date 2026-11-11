#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500002],sum,ans,l=1,r=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[1];
	while(l<=r&&r<=n){
		if((r-l+1)*a[r]-sum<=m){
			ans=max(ans,r-l+1);
			if(r<n){
				++r;
				sum+=a[r];
			}
			else{
				sum-=a[l];
				++l;
			}
		}
		else{
			sum-=a[l];
			++l;
		}
	}
	cout<<ans;
	return 0;
} 
