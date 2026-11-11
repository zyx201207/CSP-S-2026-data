#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using arr=array<ll,2>;
const ll N=1e6+10;
ll n;
arr a[N];
void solve(){
	cin>>n;
	ll f=0;
	for(ll i=1;i<=n;i++){
		ll num;char c;cin>>num>>c;
		a[i][0]=num;
		f=max(num,f);
		a[i][1]=int(c-'a');
	}
	if(f>=500){
		ll ans=0;
		ll sum=1e18;
		for(ll i=1,j=n;i<j;){
			while(a[i][0]<=a[j][0]&&j>i){
				if(a[i][1]!=a[j][1])a[j][0]-=a[i][0];
				if(a[i][1]!=a[j][1])ans+=a[i][0];
				i++;
			}
			while(a[i][0]>a[j][0]&&j>i){
				if(a[i][1]!=a[j][1])a[i][0]-=a[j][0];
				if(a[i][1]!=a[j][1])ans+=a[j][0];
				j--;
			}
		}
		sum=min(sum,ans);ans=0;
		for(ll i=1,j=n;i<j;){
			if(a[i][0]>=a[j][0]){
				ll cnt=a[i][0];
				while(a[j][0]<=cnt){
					cnt-=a[j][0];
					if(a[i][1]!=a[j][1]) ans+=a[j][0];
					a[j][0]=0;
					j--;
				}
				ans+=(a[j][0]-cnt);
				a[j][0]-=cnt;
			}else{
				ll cnt=a[j][0];
				while(a[i][0]<=cnt){
					cnt-=a[i][0];
					if(a[i][1]!=a[j][1]) ans+=a[i][0];
					a[i][0]=0;
					i++;
				}
				ans+=(a[i][0]-cnt);
				a[i][0]-=cnt;
			}
		}
		sum=min(sum,ans);
		cout<<sum;
	}else{
		string s;
		s=" "+s;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=a[i][0];j++)s+=char(a[i][1]+'a');
		}
		ll ans=0;
		//cout<<s.size()<<"\n";
		for(ll i=1;i<=(s.size()+1)/2;i++){
			if(s[i]!=s[s.size()-i]) ans++;
		}
		cout<<ans;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ll t;cin>>t;while(t--)
	solve();
	return 0;
}
