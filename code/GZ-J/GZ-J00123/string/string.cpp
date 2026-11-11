//GZ-J00123 »ÆºÆÈ»
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void fx(){
	ll n;cin>>n;
	vector<pair<ll,char> >a(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	ll l=1 ,r=n;ll ans=0;
	while(l<r){
		if(a[l].second==a[r].second){
			if(a[l].first>a[r].first){
				a[l].first-=a[r].first;a[r].first=0;r--;
			}
			else if(a[l].first<a[r].first){
				a[r].first-=a[l].first;a[l].first=0;l++;
			}
			else a[r].first=a[l].first=0,l++,r--;
		}
		else {
			if(a[l].first>a[r].first){
				ans+=a[r].first,a[l].first-=a[r].first;a[r].first=0;r--;
			}
			else if(a[l].first<a[r].first){
				ans+=a[l].first;
				a[r].first-=a[l].first;a[l].first=0;l++;
			}
			else ans+=a[l].first,a[r].first=a[l].first=0,l++,r--;
		}
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t=1;
	while(t--)fx();
}
