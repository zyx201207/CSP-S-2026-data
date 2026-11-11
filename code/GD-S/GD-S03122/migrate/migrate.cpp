#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
const int N=2e6+5;
int n,fa[N],rk[N],son[N],lst[N];
ll a[N],d,f[N],g[N];
void Mutsumi(){
	scanf("%d%lld",&n,&d); ll res=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i),fa[i]=lower_bound(a+1,a+1+i,a[i]-d)-a;
		if(i^fa[i]) rk[i]=++son[fa[i]]; f[i]=1,g[i]=0;
	}
	for(int i=n;i;i--){
//		printf("%lld");
		res+=g[i];
		if(i==fa[i]) continue;
		f[fa[i]]+=f[i],g[fa[i]]+=g[i];
		if(son[i]==1&&lst[fa[i]]&&rk[i]==son[fa[i]]-1){
			res+=f[lst[fa[i]]]-1;
//			for(int j=1;j<=n;j++)
//				if(fa[j]==lst[fa[i]]&&j!=lst[fa[i]]&&a[j]<=a[lst[i]]+d)
//					res+=f[j];
		}
		lst[fa[i]]=i;
		if(rk[i]==son[fa[i]]-1) g[fa[i]]+=f[i]-1;
//		if(i==2) printf("%d %d \n",r[i])
	}
	for(int i=1;i<=n;i++) son[i]=lst[i]=rk[i]=0;
	printf("%lld\n",res);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T=1; scanf("%d%d",&C,&T);
	while(T--) Mutsumi();
	return 0;
}
