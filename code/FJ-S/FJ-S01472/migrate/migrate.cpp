#include<bits/stdc++.h>
#define eh(...) for(const auto& __VA_ARGS__)
#define pb(...) push_back(__VA_ARGS__) 
using namespace std;
using ll = long long;
const ll maxn=2e6+10;
const ll inf=1e18+7;
inline ll read(){
	ll res=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
	return res*f; 
}
struct Node {
	ll w,num;
}dp[maxn];
ll L[maxn],R[maxn],owo[maxn];
inline void operate(){
	ll n=read(),d=read();
	for (ll i=1;i<=n;++i)
		owo[i]=read();
	
	for (ll i=1,l=1,r=1;i<=n;++i){
		while (owo[l]<owo[i]-d) l++;
		r=max(r,l);
		while (r<n && owo[r+1]<=owo[i]+d) r++;
		L[i]=l,R[i]=r;
	}
	
	ll ans=0;
	for (ll i=1;i<=n;++i){
		for (ll j=i+1;j<=n;++j){
			if (L[j]==j) break;
			if (L[j]<=i) dp[j]={1,1};
			else{
				dp[j].w=dp[L[j]].w+1,
				dp[j].num=0;
				for (ll k=L[j];k<j;++k)
					if (dp[k].w+1==dp[j].w)
						dp[j].num+=dp[k].num;
			}
			ans+=(dp[j].num==2);
		}
	}
	printf("%lld\n",ans);
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	
	ll c=read(),Z=read();
	while (Z--) operate();
} 
