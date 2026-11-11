#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
using ll=long long;
ll n,m;
ll a[N],b[N][N],ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=1){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n-i+1;j++){
				if(i==1) b[i][j]=a[j];
				else if(i==2) b[i][j]=a[j+1]-a[j];
				else b[i][j]=b[i-1][j]+b[2][i+j-2];
				//cout<<b[i][j]<<' ';
			}	
			//cout<<'\n';
		}
		for(ll i=1;i<=n;i++){
			ll sum=0;
			for(ll j=i,k=1;j>=1;j--,k++){
				sum+=b[k][j];
			}
			if(sum-a[i]<=m) ans=i;
		}
		cout<<ans;
	}
	else{
		ll x=a[2]-a[1];
		ll l=1,r=m;
		while(l<=r){
			ll mid=(l+r)/2;
			ll tmp=mid*(mid+1)/2*x;
			if(tmp<m) l=mid+1,ans=mid;
			else if(tmp>m) r=mid-1;
			else {
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
	}
	return 0;
}
