#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],num[300010];
bool check(ll x,ll mb){
	string s;
	for(ll i=x;i<=n;i++){
		ll d=0;
		if(s.find(char(a[i]-'0'))!=string::npos){
			d=s.find(char(a[i]-'0'));
			s.erase(d,s.size()-d);
			cout<<s<<endl;
		}s+=char(a[i]+'0');
	}for(ll j=0;j<ll(s.size());j++) if(ll(s[j]-'0')==mb) return true;
	else return false;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=m;i++){
		ll l=1,r=n;
        while(l<r){
			ll mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}printf("%lld ",n-l+1);
	}
    return 0;
}
