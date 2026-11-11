#include<bits/stdc++.h>
#define ll long long
using namespace std;;

const int N=5e5+5;

ll n,m,mx=-1,id,ans;
ll a[N],s[N];
map<ll,ll> mp;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		if(mp[a[i]]>mx){
			id=a[i];
			mx=mp[a[i]];
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) continue;
		int l=1,r=i-1,tot=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m){
				r=mid-1;
				tot=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,(ll)i-tot+mp[a[i]]);
	}
	cout<<ans;
	return 0;
}
