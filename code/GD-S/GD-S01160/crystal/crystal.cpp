#include<bits/stdc++.h>
#define ls(x) (x)<<1
#define rs(x) (x)<<1|1
using namespace std;
using ll=long long;
const int N=5e5+10,inf=1e18+2;
ll n,m,ans,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fa=1,fb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fa&=(a[i]==i);
	}
	ll d=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=d){
			fb=0;
			break;
		}
	}
	if(m==0){
		ll cnt=1;
		a[0]=a[1];
		for(int i=1;i<=n;i++){
			ans=max(cnt,ans);
			if(a[i]==a[i-1])cnt++;
			else cnt=1;
			ans=max(cnt,ans);
//			cout<<cnt<<'\n'; 
		}
		cout<<ans;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(abs(a[1]-a[2])<=m)cout<<2;
		else cout<<1;
		return 0;
	}
	if(fa){
		ll p=(n-1)*n/2;
		if(m>=p){
			cout<<n;
			return 0;
		}
		for(int i=n;i>=1;i--){
			if(m>=(i-1)*i/2){
				cout<<i;
				return 0;
			}
		} 
	}
	if(fb){
		ll p=d*(n-1)*n/2;
		if(m>=p){
			cout<<n;
			return 0;
		}
		for(int i=n;i>=1;i--){
			if(m>=d*(i-1)*i/2){
				cout<<i;
				return 0;
			}
		} 
	} 
}
