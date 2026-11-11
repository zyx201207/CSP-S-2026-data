#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		string s;
		for(ll j=i;j<=n;j++){
			stringstream sin;
			sin<<a[j];
			string t;
			sin>>t;
			if(s.find(t)!=string::npos) s=t;
			else s+=t;
		}
		
		for(ll j=0;j<s.size();j++) cnt[s[j]-'0']++;
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	return 0;
}
