#include <bits/stdc++.h>
#define ll long long
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
const ll N=2e6,INF=1e18;
ll C,T,n,d;
ll a[N+5];
ll ans;
ll nxt[N+5],pre[N+5];
ll f[N+5],g[N+5];
bool ck1(ll l,ll r){
	f[l]=0,g[l]=1;
	for(ll i=l+1;i<=r;i++){
		f[i]=INF,g[i]=0;
		for(ll j=i-1;j>=pre[i] && j>=l;j--){
			f[i]=min(f[i],f[j]+1);
		}
		for(ll j=i-1;j>=pre[i] && j>=l;j--){
//			if(i==4) cout<<j<<endl;;
			if(f[i]==f[j]+1){
				g[i]+=g[j];
			}
		}
//		cout<<i<<' '<<f[i]<<" "<<g[i]<<endl;
	}
//	cout<<f[r]<<" "<<g[r]<<endl;
	return f[r]<=INF && g[r]==2;
}
void case1(){
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(ck1(i,j)) ans++;
		}
	}
//	cout<<ck1(1,4);
//	ck1(1,4);
	printf("%lld\n",ans);
	return;
}
void caseA(){
	if(a[2]-a[1]>d){
		printf("0\n");
		return;
	}
	ll v=a[2]-a[1];
	for(ll len=2;len<=n;len++){
		ll cnt=n-len+1;
		ll k=d/v;
		ll stp=(len-1)/k,res=(len-1)%k;
		if(res!=0 && stp==1){
			ans+=cnt;
		}
	}
	printf("%lld\n",ans);
	return;
}
void caseB(){
	printf("0\n");
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n==1){
			printf("0\n");
			continue;
		}
		ll pos=1;
		for(ll i=1;i<=n;i++){
			while(pos+1<=n && a[pos+1]-a[i]<=d) pos++;
			nxt[i]=pos;
		}
		pos=n;
		for(ll i=n;i>=1;i--){
			while(pos-1>=1 && a[i]-a[pos-1]<=d) pos--;
			pre[i]=pos;
		}
		if(C>=1 && C<=10){
			case1();
		}
		else if(C>=11 && C<=12){
			caseA();
		}
		else if(C>=13 && C<=14){
			caseB();
		}
//		else if(C>=15 && C<=18){
//			caseC();
//		}
	}
	return 0;
}
/*
1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
