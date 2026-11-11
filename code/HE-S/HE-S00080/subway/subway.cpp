#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long

//#define flame

#ifndef flame
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define pc(x) (p3==obuf+(1<<20)&&(fwrite(obuf,1,p3-obuf,stdout),p3=obuf),*p3++=(x))
#else
#define gc() getchar()
#define pc(x) putchar(x)
#endif
#define read(x)({\
		x=0;\
		bool fl=false;\
		char ch=gc();\
		while(!isdigit(ch)) {\
			if(ch=='-') fl=true;\
			ch=gc();\
		}\
		while(isdigit(ch)) (x)=((x)<<1)+((x)<<3)+ch-48,ch=gc();\
		x=fl?-x:x;\
	})
using namespace std;
char buf[1<<20],*p1=buf,*p2=buf,obuf[1<<20],*p3=obuf;
struct IO {
	~IO() {
		fwrite(obuf,1,p3-obuf,stdout);
	}
} io;
template<typename t>
inline void write(t x) {
	if(x==0) {
		pc('0');
		return ;
	}
	if(x<0) {
		x=-x;
		pc('-');
	}
	char stk[20];
	int top=0;
	do {
		stk[top++]=x%10,x/=10;
	} while(x);
	while(top) pc(stk[--top]+48);
	return ;
}
constexpr int N=5e5+10;
int c,n,m,d,q;
int w[510];
ll f[510][510];
vector<pair<int,ll> > v[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(c),read(q);
	for(int i=1; i<=m; i++) {
		read(w[i]);
	}
	for(int i=1; i<=n; i++) {
		int x;
		read(x);
		while(x--) {
			ll b;
			read(c),read(b);
			v[c].push_back({i,b});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(auto i:v) {
		if(i.size()>1) {
			for(auto j:i) {
				for(auto k:i) {
					if(k.first==j.first) continue;
					f[k.first][j.first]=min(f[k.first][j.first],(ll)k.second+j.second);
					f[j.first][k.first]=min(f[j.first][k.first],(ll)k.second+j.second);
				}
			}
		}
	}
	for(int i=1; i<=n; i++) f[i][i]=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%lld ",f[i][j]);
//		}
//		puts("");
//	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%lld ",f[i][j]);
//		}
//		puts("");
//	}
	while(q--) {
		int x,y;
		read(x);
		read(y);
		ll ans=0x7f7f7f7f;
		for(auto i:v[x]) {
			for(auto j:v[y]) {
//				printf("%lld %lld %lld %lld\n",ans,i.second,f[i.first][j.first],j.second);
				ans=min(ans,(ll)i.second+f[i.first][j.first]+(ll)j.second);
			}
		}
		write(ans+w[x]+w[y]);
		pc('\n');
	}
	return 0;
}
//Cause now I know that pain cannot define the past.
//We are built to overcome endless mishap.
//大样例567爆栈了
//不知道结果如何,就这样吧 


//Open your eyes,dear Damocles.
//Tell me what tied to my ceiling.
//I've got everything everyting.
//I've got plenty plenty of the good, 
//plenty plenty of the worst.
//All seem splendid.
//Serve on the silver dish.
//With each great power.
//Comes a great terro(忘了咋拼了).
//That's what they say,they want us to believe.
//So what of the dreams I try to achieve to,
//Are light years far from the reality we know.
//Mirror,mirror who's my living proof.  
