//GZ-J00123 »ÆºÆÈ» 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void fx(){
	ll n;cin>>n;
	ll m;cin>>m;ll ans=0;
	vector<pair<string,ll> >a(n+1,make_pair("",0));
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;a[i].second=x;
		for(ll j=0;j<32;j++){
			a[i].first=((x&1)?"1":"0")+a[i].first;
			x>>=1;
		}
	}
	sort(a.begin()+1,a.end(),greater<pair<string,ll> >());
	for(ll i=0;i<32;i++){
		vector<ll>val;
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			string s=a[j].first;
			if(s[i]=='1')cnt++,val.push_back(a[j].second);
			if(cnt==m)break;
		}
		if(cnt==m){
			ans=val[0];
			for(ll i=1;i<val.size();i++)ans&=val[i];
			break;
		}
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll t=1;
	while(t--)fx();
}
