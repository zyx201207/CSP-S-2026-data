#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=2000005;
int nxt[Maxn],n;
ll x[Maxn],d,ans,lc[Maxn],rc[Maxn];
ll de[Maxn];
void Cov(int L,int R,ll v){if (L<=R){de[L]+=v;de[R+1]-=v;}}
void work(){
	scanf("%d%lld",&n,&d);ans=0;nxt[n]=n;
	for(int i=1;i<=n;++i) scanf("%lld",x+i);
	for(int i=n-1;i;--i){
		nxt[i]=nxt[i+1];
		while(x[nxt[i]]-x[i]>d) --nxt[i];
	}
	for(int i=n;i;--i){
		int v=nxt[i];
		if (v>i){
			rc[i]=v-i+1;
			if (nxt[v]>v&&nxt[v-1]<nxt[v]) rc[i]+=rc[nxt[v]]+nxt[v]-nxt[v-1]-1;
		}
		else rc[i]=1;
	}
	for(int i=1;i<=n;++i){
		++lc[i];int v=nxt[i];
		if (v>i&&nxt[i-1]!=v) lc[v]+=lc[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) de[j]=0;
		Cov(i,nxt[i],1);
		for(int j=i;nxt[j]!=j;j=nxt[j]){
			for(int k=j+1;k<=nxt[j];++k) de[k]+=de[k-1];
			for(int k=j+1;k<=nxt[j];++k) if (nxt[k]>nxt[j]){
				Cov(nxt[j]+1,nxt[k],de[k]);
			}
		}
		for(int j=1;j<=n;++j) if (de[j]==2) ++ans;
	}
	/*
	for(int i=1;i<=n;++i) cerr<<nxt[i]<<' ';
	cerr<<endl;
	for(int i=1;i<=n;++i) cerr<<rc[i]<<' ';
	cerr<<endl;
	for(int i=1,lst=0;i<=n;++i) if (nxt[i]==i){ans+=1ll*(i-lst)*(i-lst+1)/2;lst=i;}
	for(int i=1;i<=n;++i) ans-=rc[i];
	cerr<<ans<<endl;
	cerr<<endl;
	cerr<<nxt[nxt[2]]<<endl;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j) de[j]=0;
		for(int j=i;nxt[j]!=j;j=nxt[j]){
			if (nxt[j]>j+1&&j>2){
				if (nxt[nxt[j]]>j&&nxt[nxt[j]]==nxt[nxt[j-2]]) Cov(nxt[j]+1,n);
				if (nxt[nxt[j]]>j&&nxt[nxt[j-2]]>nxt[j]) Cov(nxt[j]+1,nxt[nxt[j-2]]);
			}
			int v=nxt[j];int vv=nxt[v];int vvv=nxt[vv];
			if (v>j&&vv>v&&vvv>vv&&nxt[v-1]>=vv-1&&nxt[vv-1]==vvv) Cov(vv+1,n);
			if (v>j&&vv>v&&vvv>vv&&nxt[v-1]>=vv-1) Cov(vv+1,nxt[vv-1]);
		}
		for(int j=1;j<=n;++j) de[j]+=de[j-1];
		for(int j=1;j<=n;++j) if (de[j]) --ans;
		cerr<<i<<endl;
		for(int j=1;j<=n;++j) cerr<<de[j]<<' ';
		cerr<<endl;
	}*/
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i) lc[i]=rc[i]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--) work();
	return 0;
}
