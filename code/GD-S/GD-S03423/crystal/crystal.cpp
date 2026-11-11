#include<bits/stdc++.h>
#define ll long long 
#define fg cout<<"！！！！！！！！！！！！！！！！！！！！！！！！！！"<<endl
#define inf (ll)1e18
using namespace std;
const int mod=998244353,N=5e5+5;
int M1;
int ans;
ll n,m;
ll a[N],sum[N];
void For_aiur(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int r=1,l=1;r<=n;r++){
		sum[r]=sum[r-1]+a[r];
		while(a[r]*(r-l+1)-(sum[r]-sum[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
}
int M2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();cin.tie();cout.tie();
	int wlae=1;
//	cin>>wlae;
	while(wlae--) For_aiur();
	return 0;
}
/*
315275
*/
