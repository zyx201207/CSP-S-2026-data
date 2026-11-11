#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10;
int Id,T,qwq;
int n,K;
int a[N];
int L[N],R[N],f[N],g[N],h[N],H[N];
int ans; 

void Solve(){
	qwq++;
	ans=0;
	scanf("%lld%lld",&n,&K);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	//if(qwq!=3) return ;
	int p=0;
	for(int i=1;i<=n;i++){
		if(p<i) p=i;
		while(p<n && a[p+1]-a[i]<=K) p++;
		R[i]=p;
	}
	p=n+1;
	for(int i=n;i;i--){
		if(p>i) p=i;
		while(p>1 && a[i]-a[p-1]<=K) p--;
		L[i]=p;
	}
	//for(int i=1;i<=n;i++) cerr<<L[i]<<" "<<R[i]<<endl;
	for(int i=1;i<=n;i++) h[i]=H[i]=0;
	for(int i=1;i<=n;i++) h[R[i]]++,H[L[i]]++;
	for(int i=1;i<=n;i++){
		if(R[L[i]]==i) f[i]=f[L[i]]+h[i];
		else f[i]=h[i]+1;
	}
	for(int i=n;i;i--){
		if(L[R[i]]==i) g[i]=g[R[i]]+H[i];
		else g[i]=H[i]+1;
	}
	//for(int i=1;i<=n;i++) cerr<<"I: "<<i<<" "<<h[i]<<" "<<f[i]<<" "<<H[i]<<" "<<g[i]<<endl;
	for(int i=1;i<=n;i++){
		//cerr<<i<<" "<<ans<<endl;
		if(R[i]==i || R[R[i]]==R[i]) continue;
		int j=R[R[i]];
		if(L[R[i]]==i && R[i]==L[j]+1 && L[L[j]]==i){
			ans+=f[i]*g[j];
			//cerr<<"I: "<<i<<" "<<j<<endl;
		}
		if(L[R[i]]==i && R[i]==L[j]+1 && L[L[j]]<i){
			ans+=g[j];
			//cerr<<"I: "<<i<<" "<<j<<endl;
		}
		if(L[R[i]]<i && R[i]==L[j]+1){
			ans+=g[j];
		}
		if(L[R[i]]<i && R[i]==L[j]+1) ans--;
		if(L[R[i]]<i) ans+=H[R[i]-1]; 
//		for(int j=R[i]+1;j<=n;j++){
////			if(L[R[i]]==i && R[i]==L[j]+1 && R[R[i]]>j){
////				//cerr<<"I: "<<i<<" "<<R[i]<<" "<<f[i]<<" "<<j<<" "<<R[R[i]]<<endl;
////				ans+=f[i];
////			}
//			if(L[R[i]]<i && R[i]==L[j]+1) ans++;
//		}
	}
	for(int j=1;j<=n;j++){
		if(L[j]==j || L[L[j]]==L[j]) continue;
		int i=L[L[j]+1];
		if(R[i]==i || R[R[i]]==R[i]) continue;
		if(L[R[i]]==i && R[i]==L[j]+1 && R[R[i]]>j && j>R[i] && L[L[j]]==i){
			//cerr<<"I: "<<i<<" "<<R[i]<<" "<<f[i]<<" "<<j<<" "<<R[R[i]]<<endl;
			ans+=f[i];
		}
		if(L[R[i]]==i && R[i]==L[j]+1 && R[R[i]]>j && j>R[i] && L[L[j]]<i){
			//cerr<<"I: "<<i<<" "<<R[i]<<" "<<f[i]<<" "<<j<<" "<<R[R[i]]<<endl;
			ans++;
		}
	}
	printf("%lld\n",ans);
	//cerr<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&Id,&T);
	while(T--) Solve();
	return 0;
}
