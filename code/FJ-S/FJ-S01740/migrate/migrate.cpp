#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
#define gc getchar()
#define pb push_back
using namespace std;
const int N=2000999;
int c,casecnt;
int n;
ll d;
ll a[N];
ll ans;
ll dp[N][2];
int le[N],ri[N];
int ma[N];
int fa[N];
int fu[N];
int mi[N];
int L[N],R[N];
int NXT[N],PRE[N];
vector<int>son[N];
void rdint(int &x){
	x=0;
	int f=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=gc;
	}
	x*=f;
	return ;
}
void rdll(ll &x){
	x=0;
	ll f=1ll;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1ll;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(ll)x*10+ch-'0';
		ch=gc;
	}
	x*=1ll*f;
	return ;
}
bool tou(int x,int y){//touch
	return (bool)(a[y]-a[x]<=d);
}
ll solve(int l,int r){
	if(r-l<=1)return 0ll;
	ll ret=0;
	FOR(i,l,r-2){
		int f=fa[i],ff=fa[fa[i]];
		if(f!=-1)dp[i][0]++;
		if(ff==-1)continue;
		int ti=0;
		if(f-1>i && tou(f-1,ff))++ti;
		if(f-2>i && tou(f-2,ff))++ti;
		if(ti==2)continue;
		if(ti==1){
			dp[f][1]+=1ll*dp[i][0];
		}
		if(ti==0){
			dp[f][1]+=1ll*dp[i][1];
			dp[f][0]+=1ll*dp[i][0]; 
		}
	}
//	FOR(i,1,n){
//		printf("%lld %lld\n",dp[i][0],dp[i][1]);
//	}
	FOR(i,l,r-2){
		int f=fa[i];
		int ft=ma[f],fta=0,ftb=0;
		if(f-1>i)fta=ma[f-1]-1;
		if(f-2>i)ftb=ma[f-2]-2;
//		printf("add:%d %lld\n",i,(ll)1ll*(ft-fta)*dp[i][1]+1ll*(fta-ftb)*dp[i][0]);
		ret+=1ll*(ft-fta)*dp[i][1];
		ret+=1ll*(fta-ftb)*dp[i][0];
	}
	return ret;
	
}
void init(){
	ans=0;
	FOR(i,0,n+1)dp[i][0]=dp[i][1]=0;
	FOR(i,1,n)PRE[i]=NXT[i]=-1;
	FOR(i,1,n)son[i].clear();
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&casecnt);
	while(casecnt--){
		rdint(n),rdll(d);
		FOR(i,1,n)rdll(a[i]);
		init();
		int yuan=1;
		FOR(i,1,n){
			while(yuan<=n && a[yuan]-a[i]<=d)++yuan;
			if(yuan-1!=i && a[yuan-1]-a[i]<=d)fa[i]=yuan-1,ma[i]=fa[i]-i;
			else fa[i]=-1,ma[i]=0;
		}
		int _yuan=n;
		ROF(i,n,1){
			while(_yuan>=1 && a[i]-a[_yuan]<=d)--_yuan;
			if(_yuan+1!=i && a[i]-a[_yuan+1]<=d)fu[i]=_yuan+1,mi[i]=i-fu[i],son[fu[i]].pb(i);
			else fu[i]=-1,mi[i]=0; 
		}
		FOR(i,1,n){
			if(fa[i]!=-1 && fu[fa[i]]==i)NXT[i]=fa[i],PRE[fa[i]]=i;
			else NXT[i]=-1;
		}
		FOR(i,1,n){
			if(PRE[i]==-1)le[i]=1;
			else le[i]=le[PRE[i]]+1;
		}
		ROF(i,n,1){
			if(NXT[i]==-1)ri[i]=1;
			else ri[i]=ri[NXT[i]]+1;
		}
		int pre=0;
//		FOR(i,1,n){
//			if(fa[i]==-1)ans+=1ll*solve(pre+1,i),pre=i;
//		}
		FOR(i,1,n-2){
			int f=fa[i];
			if(f-1<=i)continue;
//			int ff=fa[f-1];
//			if(ff==-1 || ff==f)continue;
			for(int ff:son[f-1]){
				if(ff==f)continue;
					ans+=1ll*(le[i]*ri[ff]);				
			}

		}
		printf("%lld\n",ans);
	}
	return 0;
}
