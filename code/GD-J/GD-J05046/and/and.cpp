#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
bool a[200005][32];
bool no[200005];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int z=1;
		while(x){
			if(x&1){
				a[i][z]=1;
			}
			z++;
			x>>=1; 
		} 
	}
	ll ans=0;
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(no[j])continue;
			if(a[j][i])cnt++;
		}
		if(cnt>=m){
			ans+=qpow(2,i-1);
			for(int j=1;j<=n;j++){
				if(no[j])continue;
				if(!a[j][i])no[j]=1;
			}
		}
	}
	cout<<ans;
	return 0; 
} 
