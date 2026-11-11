#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<ll>a(n+1);
	vector<char>s(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	if(n==1){cout<<0<<'\n';return 0;}
	int st=1,ed=n;
	ll zuo=min(a[1],a[n]),you=min(a[1],a[n]);
	ll ans=0;if(s[st]!=s[ed])ans+=zuo;
	while(st<ed){
		ll p=max(a[st]-zuo,a[ed]-you);
		if(p==0){
			p=min(a[st+1],a[ed-1]);
			zuo+=p;you+=p;
			zuo-=a[st];you-=a[ed];
			st++;ed--;
			if(st>=ed)break;
			if(s[st]!=s[ed])ans+=p;
			continue;
		}
		zuo+=p;you+=p;
		if(zuo>a[st]){
			while(zuo>a[st]){
				zuo-=a[st];
				st++;
				if(s[st]!=s[ed]){
					ans+=min(zuo,a[st]);
				}
			}
			continue;
		} 
		else if(you>a[ed]){
			while(you>a[ed]){
				you-=a[ed];
				ed--;
				if(s[st]!=s[ed]){
					ans+=min(you,a[ed]);
				}
			}
			continue;
		}
		if(st>=ed)break;
		if(s[st]!=s[ed])ans+=p;
	}
	cout<<ans<<'\n';
	return 0;
}
