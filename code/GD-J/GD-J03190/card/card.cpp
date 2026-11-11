#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,M=3e5+10,inf=1e15,md=1e9+7;
ll read(){
	ll ans=0,f=1;
	char s=' ';
	while(!(s>='0'&&s<='9')){
		s=getchar();
		if(s=='-')f=-1;
	}
	while(s>='0'&&s<='9'){
		ans=ans*10+s-'0';
		s=getchar();
	}
	return ans*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
ll n,m,a[N],cf[M],la[M];
vector<ll>e[M];
void dfs(ll u){
	for(auto v:e[u]){
		dfs(v);
		cf[u]+=cf[v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		la[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		cf[a[i]]++;
		if(i==la[a[i]])e[a[i+1]].push_back(a[i]);
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++){
		write(cf[i]);
		putchar(' ');
	}
	return 0;
}

