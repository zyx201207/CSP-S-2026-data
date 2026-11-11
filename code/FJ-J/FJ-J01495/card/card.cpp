#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],mp[N],siz[N];
vector<ll> g[N];
ll read(){
	char ch;ll s=0,w=1;
	while((ch=getchar())>'9' || ch<'0') if(ch=='-') w=-1;
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
void dfs(ll u){
	for(auto v:g[u]){
		dfs(v);
		siz[u]+=siz[v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		siz[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(!mp[a[i]]){
			mp[a[i]]=1;
			g[a[i+1]].push_back(a[i]);
		}
	}
	dfs(0);
	for(int i=1;i<=m;i++){
		cout<<siz[i]<<" ";
	}
	return 0;
}
