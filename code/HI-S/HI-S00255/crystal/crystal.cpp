#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500005],s[500005],ans=-1,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++)s[i]=a[i+1]-a[i];
	ll l=0,r=0;
	while(r<n){
		sum+=s[r]*(r-l+1);
		r++;
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

