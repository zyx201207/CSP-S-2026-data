#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,tmp,ans=0;
vector<ll> s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>tmp;
		s.push_back(tmp);
	}
	sort(s.begin(),s.end());
	ll r=s.size()-1,l=r,ls=m;
	while(l<=r&&l>=0){
		ll d=s[r]-s[l];
		if(d<=ls)l--,ls-=d;
		else {
			ls+=(r-l)*(s[r]-s[r-1]);
			r--;
		}
		ans=max(ans,r-l);
	}
	cout<<ans;
}