#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200008];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll mmax=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			ll ans=a[i];
			for(int j=i+1;j<=n;j++)
				mmax=max(mmax,ans&a[j]);
		}
		cout<<mmax;
		return 0;

	}else if(m==1){
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		ll ans=a[i];
		if(a[i]<mmax) break;
		for(int j=i;j<=i+m;j++)		
			ans&=a[i];
		mmax=max(ans,mmax);
	}
	cout<<mmax;
	return 0;
}
