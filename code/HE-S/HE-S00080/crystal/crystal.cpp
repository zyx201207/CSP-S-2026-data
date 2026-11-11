#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
#include<set>
#include<queue>
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
		bool f=false;\
		char ch=gc();\
		while(!isdigit(ch)) {\
			if(ch=='-') f=true;\
			ch=gc();\
		}\
		while(isdigit(ch)) (x)=((x)<<1)+((x)<<3)+ch-48,ch=gc();\
		x=f?-x:x;\
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
int n;
ll m;
ll a[N],s[N];
unordered_map<ll,int> ma;
set<ll> ss;
queue<ll> q,b;
int ans,now;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);
	read(m);
	for(int i=1; i<=n; i++) {
		int x;
		read(x);
		ss.insert(x);
		ma[x]++;
	}
	n=0;
	for(auto i:ss) s[n]=i-a[n],a[++n]=i;
//	for(int i=1;i<=n;i++) write(a[i]),pc(' '),write(ma[a[i]]),puts("");

	for(int i=1; i<=ma[a[1]]; i++) q.push(1);
	now=q.size();
	for(int i=1; i<n; i++) {
		m-=q.size()*s[i];
		while(q.size()&&m<0) m+=a[i+1]-a[q.front()],q.pop();
		for(int j=1; j<=ma[a[i+1]]; j++) q.push(i+1);
		now=q.size();
		if(now>ans) b=q;
		ans=max(ans,now);
	}
	for(auto i:ma) ans=max(ans,i.second);
	write(ans);
//	puts("");
//	while(b.size()) {
//		printf("%lld ",a[b.front()]);
//		b.pop();
//	}
	return 0;
}
//We are the weavers of the flame.
//No god to praise.
//应该A了
//高二了 
//最后一次S了
//23-26
//过去 现今 未来于此停滞——为了下一个起点 
