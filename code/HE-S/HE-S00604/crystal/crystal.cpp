#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
ll n,m,maxx,ans;
vec<ll>a,cha,b;
bool flaga=1,flagb=1;
void dfs(ll t,ll step,ll q){
	if(step==m){
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			if(b[j]==b[q])cnt++;
		}ans=max(ans,cnt);
		return;
	}
	
	for(ll i=1;i<=n;i++){
		b[i]++;
		dfs(i,step+1,q);
		b[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	if(n<3)flagb=0;
	a.resize(n+1);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)flaga=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])flagb=0;
		maxx=max(maxx,a[i]);
	}
	
	
	
	if(flagb||flaga){
		ll cr=m/(a[2]-a[1])*2;
		ll l=0,r=maxx,mid=0;
//		ll nl=LLONG_MIN,nr=LLONG_MAX;

		while(l<=r){
			mid=(l+r)/2;
			if(mid*(mid+1)==cr){
				if(m/(a[2]-a[1])==a[2]-a[1])printf("%lld",mid+1);
				else printf("%lld",mid);
				return 0;
			}
			
			if(mid*(mid+1)>cr){
				r=mid-1;
//				nr=min(nr,mid);
			}
			if(mid*(mid+1)<cr){
				l=mid+1;
//				nl=max(nl,mid);
			}
			
			
		}
		printf("%lld",l); 
		
		/*
		for(ll i=1;i<=n;i++){
			if(i*(i+1)/2==m/(a[2]-a[1])){printf("%lld",i);return 0;}
			if(i*(i+1)/2>=m/(a[2]-a[1])){printf("%lld",i-1);return 0;}
			if(-i*(-i+1)/2==m/(a[2]-a[1])){printf("%lld",-i);return 0;}
			if(-i*(-i+1)/2<=m/(a[2]-a[1])){printf("%lld",-i+1);return 0;}
		}*/return 0;
		
	}
	
	/*
	sort(a.begin()+1,a.end());
	cha.resize(n+1);
	for(ll i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	sort(cha.begin()+2,cha.end());
	*/
	b=a;
	for(ll i=1;i<=n;i++){
		dfs(i,0,i);
	}
	printf("%lld",ans);
	return 0;
}

