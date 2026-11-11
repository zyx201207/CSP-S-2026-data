#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],c[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];		
	}
	c[1]=0;
	ll sum=0;
	for(ll l=1,r=1;r<=n;r++){
		sum+=(r-l)*c[r];
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
