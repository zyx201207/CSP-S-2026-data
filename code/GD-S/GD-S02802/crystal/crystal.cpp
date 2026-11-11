#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
ll m,n,ans,pos;
ll a[N];//da->xiao
priority_queue<ll,vector<ll>,less<ll> >q;
ll check2(ll x){
	ll cnt=0,count=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)
			continue;
		if(cnt+x-a[i]>m)
			break;
		cnt+=x-a[i];
		count++;
	}
	return count;
}
bool check1(ll x){
	ll l=a[n-x+1],r=a[1];
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check2(mid)>=x)return 1;
		else r=mid-1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		q.push(x);
	}
	while(!q.empty()){
		a[++pos]=q.top();
		q.pop(); 
	}
	ll l=0,r=n;
	while(l<=r){//ans
		ll mid=(l+r)>>1;
		if(check1(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
} 
