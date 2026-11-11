#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=6e5+5;
int n,ans=1;
ll m;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
//	cerr<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++)
		cin>>a[i];
//	cerr<<a[n]<<"\n";
//	cout<<n<<" "<<m<<"\n";
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<" ";
	sort(a+1,a+n+1);
//	cerr<<a[315275]<<"\n";
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[n]-a[i]);
//		cout<<sum[i]<<" ";
	}
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<" ";
//	ll res;
	for(int i=n,j=n;i;i--){
		while(j&&sum[i]-sum[j-1]-1ll*(i-j+1)*(a[n]-a[i])<=m) j--;
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}

