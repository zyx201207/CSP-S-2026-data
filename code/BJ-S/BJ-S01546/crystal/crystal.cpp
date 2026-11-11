#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll d=0,flag=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			d=a[i]-a[i-1];
		}
		else if(i!=1&&a[i]-a[i-1]!=d){
			flag=0;
		}
	}
	if(flag==1||flag==0){
		if(n%2==1){
			ll k=a[(n+1)/2],ans=0;
			for(ll i=(n+1)/2,j=(n+1)/2;i>=1&&j<=n;i--,j++){
				if(m>=a[j]-a[i]){
					m-=a[j]-a[i];
					ans+=2;
				}
				else if(m>=k-a[i]){
					m-=k-a[i];
					ans++;
				}
				else if(m>=a[j]-k){
					m-=a[j]-k;
					ans++;
				}
				else{
					break;
				}
			}
			cout<<ans-1;
			return 0;
		}
		else{
			ll k=a[n/2],ans=0;
			for(ll i=n/2,j=n/2;i>=1&&j<=n;i--,j++){
				if(m>=a[j]-a[i]){
					m-=a[j]-a[i];
					ans+=2;
				}
				else if(m>=k-a[i]){
					m-=k-a[i];
					ans++;
				}
				else if(m>=a[j]-k){
					m-=a[j]-k;
					ans++;
				}
				else{
					break;
				}
				cout<<m<<' '<<ans<<'\n';
			}
			cout<<ans-1;
			return 0;
		}
	}
	return 0;
}