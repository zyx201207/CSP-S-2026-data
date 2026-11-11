#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],d,s=0,ans=0;
bool _7=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	d=a[2]-a[1];
	for(int i=3;i<=n;i++) _7=_7&&a[i]-a[i-1]==d;
	if(_7){
		vector<ll> b;
		for(int i=1;i<=n;i++) b.push_back(abs(a[i]-a[n/2+1]));
		sort(b.begin(),b.end());
		for(int i=0;i<b.size();i++){
			s+=b[i];
			if(s>m) break;
			ans++;
		}
		cout<<ans;
	} else{
		ll mn=LLONG_MAX,mx=LLONG_MIN;
		ans=LLONG_MIN;
		for(int i=1;i<=n;i++) mn=min(mn,a[i]),mx=max(mx,a[i]);
		for(int i=mn;i<=mx;i++){
			vector<ll> b;
			for(int j=1;j<=n;j++) b.push_back(abs(a[j]-i));
			sort(b.begin(),b.end());
			s=0;
			ll c=0;
			for(int i=0;i<b.size();i++){
				s+=b[i];
				if(s>m) break;
				c++;
			}
			ans=max(ans,c);
		}
		cout<<ans;
	}
	return 0;
}
