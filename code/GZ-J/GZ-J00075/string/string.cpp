//GZ-J00075,彭翊瑄，北师大贵阳附中 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vl vector<ll>
#define pll pair<ll,ll>
#define fi first
#define se second
void ji(){
	ll n,ans=0;
	cin>>n;
	vector<pair<char,ll> >a(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i].se>>a[i].fi;
		if(a[i].fi==a[i-1].fi){
			a[i].se+=a[i-1].se;
			a[i-1].se=0;
		}
	}
	ll l=1,r=n;
	while(l<r){
		
		if(a[l].se==0)l++;
		if(a[r].se==0)r--;
		if(a[l].se>a[r].se){
			if(a[l].se==0)l++;
			if(a[r].se==0)r--;
			while(a[l].se>0&&l<r){
				if(a[l].fi!=a[r].fi){
					if(a[l].se>=a[r].se){
						ans+=a[r].se;
						a[l].se-=a[r].se;
						r--;
					}
					else {
						ans+=a[l].se;
						a[r].se-=a[l].se;
						l++;
						break;
					}
				}
				else{
					a[l].se-=min(a[l].se,a[r].se);
					if(a[l].se==0){
						l++;
						break;
					}
				}
			}
		}
		if(a[l].se<a[r].se){
			if(a[l].se==0)l++;
			if(a[r].se==0)r--;
			while(a[r].se>0&&l<r){
				if(a[l].fi!=a[r].fi){
					if(a[r].se>=a[l].se){
						ans+=a[l].se;
						a[r].se-=a[l].se;
						l++;
					}
					else {
						ans+=a[r].se;
						a[l].se-=a[r].se;
						r--;
					}
				}
				else a[r].se-=min(a[l].se,a[r].se);
				if(a[r].se==0){
					r--;
					break;
				}
			}
		}
	}
	cout<<ans;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t=1;//cin>>t;
	while(t--){
		ji();
	} 
	return 0;
} 
