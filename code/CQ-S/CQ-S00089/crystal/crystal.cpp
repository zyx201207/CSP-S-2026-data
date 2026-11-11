#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll ans;
const int N=5e5+5,M=1e12+1;
ll a[N],sum[N];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(ll l=1,r=1;r<=n;){
		if(a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m){
			ans=max(r-l+1,ans);
			r++;
		}
		else 
			l++;
	}
	cout<<ans<<endl;
	return 0;
}

