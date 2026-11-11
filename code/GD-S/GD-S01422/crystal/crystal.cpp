#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5e5+10;
#define ll long long
ll n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[n+1]=2e18;
	ll l=1,now;
	for(ll r=1;r<=n;r++){
		now+=(r-l)*(a[r]-a[r-1]);
		while(now>m){
			now-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
