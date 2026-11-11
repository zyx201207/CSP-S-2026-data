#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
ll n,m,a[200005],ans=0,two[35];
vector<vector<ll>> dp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	two[0]=1;
	two[1]=2;
	for(ll i=2;i<=30;++i){
		two[i]=two[i-1]*2;
	}
	for(ll i=30;i>=0;--i){
		ll s=0;
		for(ll j=1;j<=n;++j){
			if((a[j]&two[i])==two[i]){
				++s;
			}
		}
		if(s>=m){
			for(ll j=1;j<=n;++j){
				if((a[j]&two[i])!=two[i]){
					a[j]=0;
				}
			}
			ans+=two[i];
		}else{
			continue;
		}
	}
	cout<<ans;
	return 0;
} 
