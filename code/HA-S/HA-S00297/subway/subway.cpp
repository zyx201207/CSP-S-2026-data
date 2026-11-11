#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1000000;
ll c,n,m,d,q;
ll w[N];

ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

bool lowbit(ll i){
	return i & -i; 
}

void add(ll x,ll i){
	while(x>0){
		w[x]+=i;
		x-=lowbit(x);
	}
}

ll sum(ll x){
	ans=0
	while(x<=n){
		ans+=w[i];
		x+=lowbit(x);
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(ll i=1;i<=m;i++){
		w[i]=read();
	}
	for(ll i=1;i<=n;i++){
		ll k;k=read();
		for(ll j=1;j<=k;j++){
			ll a,t;
			a=read();t=read();
			add(a,t);
		}
	}
	while(q--){
		ll x,y;x=read();y=read();
		cout<<sum(y)-sum(x)<<'\n';
	} 
	return 0;
}
