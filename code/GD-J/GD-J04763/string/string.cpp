#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=200050;
ll len[N];
char c[N];
pll s[N];
ll cnt_r=0;
ll ans;
ll n; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>len[i]>>c[i];
		s[i].first=cnt_r+1,s[i].second=cnt_r+len[i];
		cnt_r+=len[i];
	}
	ll i=1,j=n;
	while(i<j){
		ll li=s[i].first,ri=s[i].second;
		ll lj=s[j].first,rj=s[j].second;
		ll leni=ri-li+1,lenj=rj-lj+1;
		if(leni>lenj){
			if(c[i]!=c[j])ans+=lenj;
			s[i].first+=lenj;
			j--;
		}
		else if(leni<lenj){
			if(c[i]!=c[j])ans+=leni;
			s[j].second-=leni;
			i++;
		}
		else {
			if(c[i]!=c[j])ans+=leni;
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
