#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll a[N];
char c[N];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(ll l=1,r=n;l<=r;){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
