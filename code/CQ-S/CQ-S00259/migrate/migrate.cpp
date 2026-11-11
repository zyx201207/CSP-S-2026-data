#include<bits/stdc++.h>
#define ll long long
#define LL long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define ld long double
#define memcsh(a) memset(a,0,sizeof(a))
#define membig(a) memset(a,0x3f,sizeof(a))
#define memsma(a) memset(a,0xC1,sizeof(a))
#define sz(v) (int)v.size()
#define MX 0x3f3f3f3f
#define MN 0xC1C1C1C1
#define MXll 0x3f3f3f3f3f3f3f3f
#define MNll 0xC1C1C1C1C1C1C1C1
#define all(v) v.begin(),v.end()
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=2e6+5,mod=1e9+7;
bool start_MLE;
//char sr[1<<21],sc[1<<21],*rx=sr,*ry=sr,*cx=sc,*cy=sc+(1<<21);
//#define getc() (rx==ry&&(ry=(rx=sr)+fread(sr,1,sizeof(sr),stdin)),rx==ry?EOF:*rx++)
//LL read(){
//	LL x=0;
//	ll y=1,c=getc();
//	for(;!isdigit(c);c=getc())if(c=='-')y=-1;
//	for(;isdigit(c);c=getc())x=(x<<3)+(x<<1)+(c^48);
//	return x*y;
//}
//#define putc(c) (cx==cy&&(fwrite(sc,1,sizeof(sc),stdout),cx=sc),*cx++=c)
//void write(LL x){
//	if(x<0)putc('-'),x=-x;
//	if(x>9)write(x/10);
//	putc(x%10^48);
//	return;
//}
//struct code_end{
//	~code_end(){
//		fwrite(sc,1,cx-sc,stdout);
//	}
//}codend;
ll hyw,T,a[N],nxt[N],last[N],f0[N],f1[N],R[N];
bitset<N>e;
bool end_MLE;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>hyw>>T;
	while(T--){
		ll n,d;
		cin>>n>>d;
		rep(i,1,n)cin>>a[i];
		ll r=n,l=n+1;
		while(a[n]-a[l-1]<=d)--l;
		last[n]=l;
		last[n+1]=0;
		nxt[0]=0;
		R[n]=n;
		f0[n]=f1[n]=0;
		ll ans=0;
		per(i,n-1,1){
			while(a[r]-a[i]>d)--r;
			while(l-1&&a[i]-a[l-1]<=d)--l;
			nxt[i]=r,last[i]=l;
		}
		e[n]=0;
//		rep(i,1,n)cout<<last[i]<<' '<<nxt[i]<<'\n';
		per(i,n-1,1){
			r=nxt[i],l=last[i];
			if(last[r]<i){
				f0[i]=f1[i]=0;
				R[i]=r;
				if(r<n)ans+=(r-min(max(last[r+1],l+1),r))+f0[r];
				e[i]=0;
				continue;
			}
			R[i]=R[r];
			e[i]=e[r];
			if(last[last[R[i]]]==i){
				e[i]=1;
			}
//			cout<<i<<' '<<R[i]<<' '<<e[i]<<'\n';
			ll sum=r-min(max({last[r+1],nxt[i-1]+1,l+1}),r);
			f1[i]=f1[r]+sum;
			f0[i]=f0[r];
			if(e[i]||(max((ll)i,last[last[R[i]]])==i&&last[R[i]]!=i)){
//				cout<<" "<<f0[R[i]]<<' '<<f1[r]<<' '<<(r-min(max(last[r+1],l+1),r))<<'\n';
				ans+=f0[R[i]]+f1[r]+(r-min(max(last[r+1],l+1),r));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

