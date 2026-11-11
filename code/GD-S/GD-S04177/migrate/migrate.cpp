#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e6+5;
int type,_,n,s[N],p[N];
ll a[N],d,g[N],f[N],ans;
vector<int>e[N];
ll read(){
	ll x(0),f(1);char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	do x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	while(isdigit(ch));
	return x*f;
}
void Clear(){
	ans=0;
	for(int i=1;i<=n;++i)f[i]=g[i]=s[i]=p[i]=0,e[i].clear();
}
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;++i)a[i]=read();
	Clear();
	for(int i=1,j=1;i<=n;++i){
		while(j<n&&a[j+1]-a[i]<=d)++j;
		p[i]=j;
	}
	for(int i=2;i<=n;++i){
		if(p[i]==i)continue;
		if(p[i-1]==p[i])s[i]=1;
		if(i>2&&p[i-2]==p[i])s[i]=2;
	}
	for(int i=n;i;--i){
		if(s[i])g[i]=0;
		else g[i]=g[p[i]]+p[i]-p[i-1];
	}
	for(int i=1;i<=n;++i)
		if(p[i]!=i)e[p[i]].push_back(i);
	for(int i=1;i<=n;++i){
		if(s[i])continue;
		for(auto v : e[i])
			f[i]+=1+f[v];
	}
	for(int i=3;i<=n;++i){
		if(s[i]!=1)continue;
		if(p[i-2]<i)continue;
		ll val=g[p[i]]+p[i]-p[i-2];
		for(auto v : e[i]){
			ans+=val;
			if(v!=1&&p[v-1]<i-1)ans+=f[v]*val;
		}
	}
	for(int i=3;i<=n;++i){
		if(s[i]||p[i-2]<i)continue;
		ll val=p[i-1]-p[i-2];
		for(auto v : e[i]){
			ans+=val;
			if(v!=1&&p[v-1]<i-1)ans+=f[v]*val;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	type=read(),_=read();
	while(_--)solve();
	return 0;
} 
