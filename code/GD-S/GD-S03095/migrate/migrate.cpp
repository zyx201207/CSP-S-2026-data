#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+6;
ll c,t,n,d,a[N],w,s;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
ll getde(ll l,ll r){
	ll rt=l,res=0;
	while(rt<r){
		ll lrt=rt;
		ll g=lower_bound(a+1,a+n+1,a[rt]+d)-a;
		if(a[g]==a[l]+d) rt=g;
		else{
			rt=g-1;
		}
		res++;
		if(lrt==rt) return -1;
	}
	return res;
}
void dfs(ll u,ll ud,ll nd,ll r){
	if(nd>ud) return;
	if(u==r){
		if(nd==ud) w++;
		return;
	}
	for(int i=u+1;i<=r;++i){
		if(a[i]<=a[u]+d){
			nd++;
			dfs(i,ud,nd,r);
			nd--;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		s=0;
		for(int i=1;i<=n;++i) a[i]=read();
		for(int l=1;l<=n;l++){
			for(int r=l+3;r<=n;r++){
				w=0;
				dfs(l,getde(l,r),0,r);
				if(w==2){
					s++;
				}
			}
		}
		cout<<s;
		if(t!=0) cout<<endl;
	}
	return 0;
}
