#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[1000000+10];
bool flag=1,blag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		if(a[i]!=i){
			flag=0;
			break;
		}
	}
	ll da=a[2]-a[1];
	for(ll i=2;i<=n;i++){
		if(a[i]-a[i-1]!=da){
			blag=0;
			break;
		}
	}
	ll cnt=0,ans=0;
	if(flag==1){
		for(ll i=1;i<=n;i++){
			if(m!=0&&m-i>=0){
				m-=i;
				cnt++;
			}
		}
		cout<<cnt+1;
		return 0;
	}else if(blag==1){
		for(ll i=1;i<=n;i++){
			if(m!=0&&m-da*i>=0){
				m-=da*i;
				cnt++;
			}
		}
		cout<<cnt+1;
		return 0;
	}else{
		ll sum=0;
		sort(a+1,a+n+1);
			if(a[n/2]<=a[n/2+1]){
				sum=a[n/2+1];
				sort(a+1,a+n/2+1);
				for(ll i=n/2+1;i>=1;i--){
					if(m!=0&&m-(sum-a[i])>=0){
						if(a[i]==a[i+1]||a[i]==a[i-1]){
							ans++;
						}
						cnt++;
						m=m-(sum-a[i]);
					} 
				}
				cout<<cnt+ans;
				return 0;
			}else{
				sum=a[n/2];
				sort(a+1,a+n/2);
				for(ll i=n/2;i>=1;i--){
					if(a[i]==a[i+1]||a[i]==a[i-1]){
							ans++;
					}
					if(m!=0&&m-(sum-a[i])>=0){
						cnt++;
						m=m-(sum-a[i]);
					}
				}
				cout<<cnt+ans;
			}
	}
	return 0;
} 
