#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,a[N],ansy;
vector<ll> v,v2;
bool b[N];
void print(ll cur){
	ll x=(1<<32)-1;
	for(ll i=1;i<cur;i++){
		if(b[i]) x&=a[i];
	}
	ansy=max(ansy,x);
}
void dfs(ll cur,ll curx){
	if(curx==m){
		print(cur);
		return ;
	}
	if(cur>n) return ;
	if(curx+n-cur+1<m) return ;
	for(ll i=0;i<=1;i++){
		b[cur]=i;
		if(i==1) dfs(cur+1,curx+1);
		else dfs(cur+1,curx);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(m==n){
		ll ans=a[1];
		printf("%lld",ans);
	}
	else if(m==1){
		ll maxn=a[1];
		for(ll i=2;i<=n;i++) maxn=max(maxn,a[i]);
		printf("%lld",maxn);
	}
	else if(n<=5000 && m==2){
		ll maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++) maxn=max(maxn,a[i]&a[j]);
		}
		printf("%lld",maxn);
	}
	else if(n<=25){
		dfs(1,0);
		printf("%lld",ansy);
	}
	else{
        for(ll i=1;i<=n;i++) v.push_back(a[i]);
        for(ll i=30;i>=0;i--){
            for(ll j=0;j<v.size();j++){
                if((v[j]&(1<<i))!=0) v2.push_back(v[j]);
            }
            if(v2.size()>=m) v=v2;
            v2.clear();
        }
        if(v.size()==n){
            if(v[0]==v[1]) printf("%lld",v[0]);
            else printf("%lld",(ll)0);
        }
        else{
            ll ans=v[0];
            for(ll i=1;i<v.size();i++) ans&=v[i];
            printf("%lld",ans);
        }
	}
	return 0;
}
