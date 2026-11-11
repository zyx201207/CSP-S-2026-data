#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10; 
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
ll n,m,a[N],s[N],ans;
queue<ll> q;
ll value(ll l,ll r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		while(!q.empty() && value(q.front(),i)>m)q.pop();
		q.push(i);
		ans=max(ans,(ll)q.size());
	}
	cout<<ans;
	return 0;
}
