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
const int N=5e5+5,mod=1e9+7;
bool start_MLE;
char sr[1<<21],sc[1<<21],*rx=sr,*ry=sr,*cx=sc,*cy=sc+(1<<21);
#define getc() (rx==ry&&(ry=(rx=sr)+fread(sr,1,sizeof(sr),stdin)),rx==ry?EOF:*rx++)
LL read(){
	LL x=0;
	ll y=1,c=getc();
	for(;!isdigit(c);c=getc())if(c=='-')y=-1;
	for(;isdigit(c);c=getc())x=(x<<3)+(x<<1)+(c^48);
	return x*y;
}
#define putc(c) (cx==cy&&(fwrite(sc,1,sizeof(sc),stdout),cx=sc),*cx++=c)
void write(LL x){
	if(x<0)putc('-'),x=-x;
	if(x>9)write(x/10);
	putc(x%10^48);
	return;
}
struct code_end{
	~code_end(){
		fwrite(sc,1,cx-sc,stdout);
	}
}codend;
ll hyw,n,m,d,q,w[N];
pii a[N][20];
ll len[N];
ll f[505][505];
bool end_MLE;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	hyw=read(),n=read(),m=read(),d=read(),q=read();
	rep(i,1,m){
		w[i]=read();
	}
	rep(i,1,n){
		ll k,x,y;
		k=read();
		rep(j,1,k){
			x=read(),y=read();
			a[x][++len[x]]=pii{i,y};
		}
	}
	membig(f);
	rep(i,1,n)f[i][i]=0;
	rep(i,1,m){
		ll k=len[i];
		rep(j,1,k){
			ll x=a[i][j].fi,x_=a[i][j].se,y,y_;
			rep(h,1,k){
				y=a[i][h].fi,y_=a[i][h].se+x_;
				f[x][y]=min(f[x][y],y_);
//				cout<<x<<"->"<<y<<'\n';
			}
		}
	}
	rep(h,1,n){
		rep(i,1,n){
			rep(j,1,n){
				f[i][j]=min(f[i][j],f[h][i]+f[h][j]);
			}
		}
	}
//	rep(i,1,n){
//		rep(j,1,n)cout<<(f[i][j]==MX?-1:f[i][j])<<' ';
//		cout<<'\n';
//	}
	while(q--){
		ll s,t;
		s=read(),t=read();
		ll mn=MXll;
		rep(i,1,len[s]){
			ll k=len[t],x=a[s][i].fi,x_=a[s][i].se,y,y_;
			rep(j,1,k){
				y=a[t][j].fi,y_=a[t][j].se+x_;
				mn=min(mn,f[x][y]+y_);
			}
		}
		write(w[s]+w[t]+mn);
		putc('\n');
	}
	return 0;
}

