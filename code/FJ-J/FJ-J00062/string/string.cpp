#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200005;
ll n,num[N],ans,l,r,cnt,cnt2;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&num[i]);
		cin>>c[i];
	}
	l=1,r=n,cnt=num[1],cnt2=num[n];
	while(l<r){
		ll cntt=min(cnt,cnt2);
		cnt-=cntt,cnt2-=cntt;
		if(c[l]!=c[r])ans+=cntt;
		if(cnt==0){
			++l;
			cnt=num[l];
		}
		if(cnt2==0){
			--r;
			cnt2=num[r];
		} 
	}
	printf("%lld",ans);
	return 0;
}
