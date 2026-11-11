#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,m,ans=2e30-1,ag,ng,v;
ll a[N],s[N];
ll cu[30]={-1},dui[30]={-1};
deque<ll> q;
ll shu(ll x){
	ll r=0,w=1;
	while(x){
		if((x&1)==1){
			r++;
			if(cu[w]==-1) cu[w]=1;
			else cu[w]=0;
		}
		x>>=1;
	}
	return r;
}
ll g(ll x){
	for(ll i = 29;i>=0;i--){
		if((x&(1<<i))==1) return i; 
	}
}
bool cmp(ll x,ll y){
	ll xx=shu(x),yy=shu(y);
	if(xx==yy){
		return x>y;
	}
	return xx>yy;
}
bool cm(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=a[i];
	}
	sort(a+1,a+n+1,cmp);
	sort(s+1,s+n+1);
	for(ll i = 1;i<=m;i++){
		q.push_back(a[i]);
		ll tm=g(a[i]);
		if(dui[tm]==-1) dui[tm]=1;
		else dui[tm]=0;
	}
	for(ll i = 29;i>=0;i--){
		if(cu[i]==0){
			ng=i;
			break;
		} 
	}
	for(ll i = 29;i>=0;i--){
		if(dui[i]==0){
			ag=i;
			break;
		} 
	}
	if(ag<ng){
		for(ll i = ag+1;i<=ng;i++){
			if(cu[i]!=0) continue;
			auto it=upper_bound(s+1,s+n+1,1<<(i+1));
			q.pop_back();
			it--;
			v=(ll)*it;
			q.push_front(v);
			q.pop_back();
			it--;
			v=(ll)*it;
			q.push_front(v);
//			printf(" %lld",v);
		}
	}
	sort(q.begin(),q.end(),cm);
	while(!q.empty()){
		ans&=q.back();
//		printf("%lld\n",q.back());
		q.pop_back();
	}
	printf("%lld",ans);
	return 0;
}
