#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-');
	x=abs(x);
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
ll s[505][505];
ll p[505];
ll cnt[500050];
ll w[500050];
ll c,n,m,d,q,k,x,y;
int main(){
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i) w[i]=read();
	for(ll i=1;i<=n;++i){
		k=read();
		for(ll j=1;j<=k;++j){
			cin>>
		}
	}
	return 0;
}
