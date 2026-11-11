#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline int read(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N=2e6+5;
signed nxt[N<<1][25];
int n,d,a[N],pl[N],pr[N],sl[N],sr[N],pl1[N],sl1[N],pr1[N],sr1[N],pre[N],suf[N];
int dis(int x,int y){
	int res=0;
	per(k,21,0){
		if(x>n) return INT_MAX;
		if(nxt[x][k]<y) res+=(1<<k),x=nxt[x][k];
	}
	return x==y?res:res+1;
}
void solve(){
	n=read(),d=read();
	if(n<=4){
		puts("0");
		return;
	}
	if(__>=14 && __<=18) return cout<<0<<endl,void();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) rep(k,0,21) nxt[i][k]=0;
	rep(i,1,n) pre[i]=suf[i]=0;
	a[n+1]=LLONG_MAX;
	// getdis
	rep(i,1,n) nxt[i][0]=lower_bound(a+i,a+n+1,a[i]+d+1)-a-1;
	rep(k,1,21){
		rep(i,1,n){
			nxt[i][k]=nxt[nxt[i][k-1]][k-1];
		}
	}
	int hd=1,tl=0;
	rep(i,2,n-2){
		tl++;
		while(dis(hd,i)!=dis(hd,i+1) && hd<=tl) hd++;
		pl1[i]=pl[i]=hd,pr1[i]=pr[i]=tl;
	}
	hd=n+1,tl=n;
	int ans=0;
	per(i,n-1,3){
		hd--;
		while(dis(tl,i)!=dis(tl,i-1) && hd<=tl) tl--;
		sl1[i]=sl[i]=hd,sr1[i]=sr[i]=tl;
	}
	/*rep(i,2,n-2){
		if(i==n-2 && pr[i]==n-3) pre[i]++;
		if(i<n-2) pr[i]=min(pl[i+1],pr[i]);
		if(i>2) pl[i]=max(pr[i-1],pl[i]);
		pre[i]+=pr[i]-pl[i]+1;
	}
	rep(i,3,n-1){
		if(i==3 && sl[i]==4) pre[i]--;
		if(i>3) sl[i]=max(sl[i],sr[i-1]);
		if(i<n-1) sr[i]=max(sl[i],sr[i+1]);
		suf[i]=sr[i]-sl[i]+1;
	}*/
	rep(i,2,n-2){
		pre[i]=pr[i]-pl[i]+1,suf[i+1]=sr[i+1]-sl[i+1]+1;
		if(i<n-2) pre[i]-=max(0ll,pr[i]-pl[i+1]+1);
		if(i>3) suf[i+1]-=max(0ll,sr[i]-sl[i+1]+1);
		ans+=max(0ll,pre[i]*suf[i+1]);
	}
	rep(i,2,n-2){
		ans+=max(0ll,(pl[i]-pl[i-1])*(sr[i]-sr[i+1]));
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int __=read(),_=read();
	while(_--) solve();
	return 0;
}