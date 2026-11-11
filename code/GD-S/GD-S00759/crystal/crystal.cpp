#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,m,x[500005],ans=-2e9,p=-2e9,f=1,flag=1;
map<ll,ll> mp;
void dfs(int s,ll k){
	ans=max(ans,k);
	if(s>=m) return;
	for(int i=1;i<=a;i++){
		mp[x[i]]--;
		mp[x[i]+1]++;
		dfs(s+1,max(k,mp[x[i]+1]));
		mp[x[i]]++;
		mp[x[i]+1]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&a,&m);
	for(int i=1;i<=a;i++){
		scanf("%lld",&x[i]);
		if(x[i]!=i) f=0;
		if(i>=2&&x[i]-x[i-1]!=x[2]-x[1]) flag=0;
		mp[x[i]]++;
		p=max(mp[x[i]],p);
	}
	if(f==1){
		ll o=0;
		for(int i=1;i<=a;i++){
			o+=i;
			if(o>=m){
				printf("%d",i);
				return 0;
			}
		}
		return 0;
	}
	if(flag==1){
		ll o=0;
		for(int i=1;i<=a;i++){
			o+=x[2]-x[1];
			if(o>=m){
				printf("%d",i);
				return 0;
			}
		}
		return 0;
	}
	sort(x+1,x+a+1);
	dfs(0,p);
	printf("%lld",ans/2);
	return 0;
}
