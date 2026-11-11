#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
inline ll read(){
	ll f=1,x=0; char ch;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar();}
	return f*x;
}
const ll N=2e6+5;
ll _,__;
ll n,k;
vector <ll> g[N];
void add(ll u,ll v){
	g[u].pb(v);
}
int main(){
	 freopen("hub.in","r",stdin);
	 freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	_=read(),__=read();
	while(__--){
		n=read(),k=read();
		cout<<n-k-1<<'\n';
	}
	return 0;
}

