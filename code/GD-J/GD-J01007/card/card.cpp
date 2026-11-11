#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500010;
ll n,m,nxt[N],s[N],hea[N],mm,a[N],f[N],l[N];
struct lx{
	ll v,nxt;
}e[N];
void add(ll u,ll v){
	e[++mm]={v,hea[u]};
	hea[u]=mm;
}
void dfs(ll a){
	for(int i=hea[a];i;i=e[i].nxt){
		dfs(e[i].v);
		s[a]+=s[e[i].v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[a[i]]++;//统计出现次数 
		l[a[i]]=i;//保存最后出现 
	}
	for(int i=1;i<=m;i++){
		f[i]=a[l[i]+1];//父节点 
		if(l[i]+1<=n)add(a[l[i]+1],i);//建边 
	}
	for(int i=1;i<=m;i++)if(f[i]==0)dfs(i);//跑树 
	for(int i=1;i<=m;i++)printf("%lld ",s[i]);
	return 0;
}
