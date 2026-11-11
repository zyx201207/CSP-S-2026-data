#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
inline int read(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
inline ll readll(){
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	ll x=0;int f=(ch=='-'?ch=getchar(),-1:1);
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void put(int x){
	if(x>9) put(x/10);
	putchar((x%10)^48);
}
void putll(ll x){
	if(x>9) putll(x/10);
	putchar((x%10)^48);
}
int c,T,n,lp[N],rp[N];
int f[N],g[N];
ll x[N],d;
void solve(){
	n=read(),d=readll();
	for(int i=1;i<=n;i++) x[i]=readll(),f[i]=g[i]=0; 
	for(int i=1,j=1;i<=n;i++){
		while(x[i]-x[j]>d) j++;
		lp[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(x[j]-x[i]>d) j--;
		rp[i]=j;
	}
	//exit(0);
	//cout<<"lp : ";for(int i=1;i<=n;i++) cout<<lp[i]<<" ";cout<<endl;
	//cout<<"rp : ";for(int i=1;i<=n;i++) cout<<rp[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++){
		if(rp[i]==i) continue;
		f[rp[i]]++;
		if(lp[rp[i]]==i) f[rp[i]]+=f[i];
	}
	for(int i=n;i>=1;i--){
		if(lp[i]==i) continue;
		g[lp[i]]++;
		if(rp[lp[i]]==i) g[lp[i]]+=g[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int l=rp[i];
		if(l-i<2) continue;
		int k=l-1,j=rp[l];
		if(l==j) continue;
		if(lp[j]==k&&lp[k]==i){
			//cout<<i<<" and "<<j<<endl;
			ans+=(ll)f[i]*g[j];
		}
	}
	//cout<<"ans : "<<ans<<endl;
	int ju=1,jv=1;
	for(int k=1;k<n;k++){
		int l=k+1;
		int sp=0,sq=0;
		while(jv<=n&&lp[jv]<k) jv++;
		while(jv<=n&&lp[jv]<=k){
			if(jv>l){
				sp+=(x[jv]-x[l]<=d);
			}
			jv++;
		}
		while(ju<=n&&rp[ju]<l) ju++;
		while(ju<=n&&rp[ju]<=l){
			if(ju<k){
				sq+=(x[k]-x[ju]<=d);
			}
			ju++;
		}
		ans+=(ll)sp*sq;
	}
	//exit(0);
	//cout<<"ans : "<<ans<<endl;
	for(int u=1;u<=n;u++){
		int l=rp[u];
		if(l-u<2) continue;
		int i=rp[l];
		if(i==l) continue;
		if(lp[i]==l-1) ans+=g[i];
	}
	//cout<<"ans : "<<ans<<endl;
	for(int v=1;v<=n;v++){
		int k=lp[v];
		if(v-k<2) continue;
		int i=lp[k];
		if(i==k) continue;
		if(rp[i]==k+1) ans+=f[i];  
	}
	//cout<<"ans : "<<ans<<endl;
	putll(ans),putchar(10);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--) solve();
	return 0;
}
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
