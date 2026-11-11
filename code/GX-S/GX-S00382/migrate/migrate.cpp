#include<cstdio>
#include<algorithm>
using namespace std;
#define qwq Ff472130
#define ll long long
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
constexpr int N=2e5+10;
constexpr ll inf=1e18+10;

inline void read(int &x) {
	x=0;
	char ch=getchar();
	while (ch<48) ch=getchar();
	while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

inline void readl(ll &x) {
	x=0;int f=1;
	char ch=getchar();
	while (ch<48) {if(ch=='-')f=-1;ch=getchar();}
	while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();x*=f;
}

int n;
ll a[N],m;
int L[N],R[N];

inline void get_LR() {
	int lst=1;
	f(i,1,n) {
		while (a[i]-a[lst]>m) lst++;
		L[i]=lst;
	}
	lst=n;
	F(i,n,1) {
		while (a[lst]-a[i]>m) lst--;
		R[i]=lst;
	}
}

inline int work(int st) {
	static int f[N],g[N];
	f[st]=0;g[st]=1;
	int ret=0;
//	printf("work:%d\n",st);
	f(i,st+1,n) {
		if (L[i]==i) break;
		int lst=max(st,L[i]);
		f[i]=f[lst]+1;g[i]=g[lst];
        if (lst+1<i&&f[lst+1]==f[lst]) g[i]+=g[lst+1];
        if (lst+2<i&&f[lst+2]==f[lst]) g[i]+=g[lst+2];
        g[i]=min(g[i],3);
        if (g[i]==2) ret++;
//        if (g[i]==2) printf("%d ",i);
	}
//	putchar(10);
	return ret;
}

inline void solve() {
	read(n);readl(m);
	f(i,1,n) readl(a[i]);
	get_LR();
	ll sum=0;
	f(i,1,n) {
//	    printf("%d\n",work(i));
	    sum+=work(i);
	}
	printf("%lld\n",sum);
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
//    freopen("test.in","r",stdin);
//    freopen("out.out","w",stdout);
	int C,T;read(C);read(T);
	while (T--) solve();
	return 0;
}


/*
int n,cnt;
ll a[N],m;
int L[N],R[N];

inline void get_LR() {
	int lst=1;
	f(i,1,n) {
		while (a[i]-a[lst]>m) lst++;
		L[i]=lst;
	}
	lst=n;
	F(i,n,1) {
		while (a[lst]-a[i]>m) lst--;
		R[i]=lst;
	}
}

int xL;
struct Node{int l,r,g0,g1,ans;}p[N];

inline void calc(Node x,Node &y) {
	int l=y.l,r=y.r,res1=r+1,res2=r+1;
	int pos=max(x.l,x.r-1);
	if (max(L[r],xL)<pos||x.g1==3) {
		y.g1=3;
		if (y.l!=y.r) y.g0=3;
		else y.g0=0;
		y.ans=0;
		return;
	}
	while (l<=r) {
		int mid=l+r>>1;
		if (max(L[mid],xL)>=pos) res1=mid,r=mid-1;
		else l=mid+1;
	}
	l=y.l,r=y.r;pos=x.r;
	while (l<=r) {
		int mid=l+r>>1;
		if (max(L[mid],xL)>=pos) res2=mid,r=mid-1;
		else l=mid+1;
	}
	int g0=x.g0,g1=x.g1,sum=0;
	if (g0+g1==2&&res1!=r+1) sum=res2-res1;
	if (g1==2&&res2!=r+1) sum+=r-res2+1;
	y.ans=sum;
	if (max(xL,L[y.r])<x.r-1) y.g1=3;
	else if (max(xL,L[y.r])<x.r) y.g1=min(g0+g1,3ll);
	else y.g1=g1;
	if (y.l==y.r) {
		y.g0=0;
		return;
	}
	if (max(xL,L[y.r-1])<x.r-1) y.g0=3;
	else if (max(xL,L[y.r-1])<x.r) y.g0=g0+g1;
	else y.g0=g1;
}

int pre[N],nxt[N],hd,tl;
inline void del(int x) {
	int l=pre[x],r=nxt[x];
	if (!l) return;
	nxt[l]=r;pre[r]=l;pre[x]=0;nxt[x]=0;
}

inline void link(int x,int y) {
	int r=nxt[x];
	nxt[x]=y;pre[y]=x;
	nxt[y]=r;pre[r]=y;
}

inline void out() {
    puts("out:");
    for (int i=nxt[hd];i!=tl;i=nxt[i]) {
        printf("%d %d %d %d %d\n",p[i].l,p[i].r,p[i].g0,p[i].g1,p[i].ans);
    }
}

inline ll update() {
//    puts("update");
	static int st[N];
	static Node vec[N];
	int top1=0,top2=0;
	del(nxt[hd]);
	int pos=nxt[hd],now=p[pos].l;xL=now;
	ll ret=0;
	vec[++top2]={now,now,0,1,0};
	while (1) {
		while (p[pos].r<R[now]) {
			st[++top1]=pos;
			pos=nxt[pos];
		}
		if (p[pos].r==R[now]) {
			if (now!=R[now]) vec[++top2]={now+1,R[now],0,0,0};
			st[++top1]=pos;
			break;
		}
		vec[++top2]={now+1,R[now],0,0,0};
		now=R[now];
	}
	f(c,1,top1) {
		int i=st[c];
		ret-=p[i].ans;
		del(i);
	}
	f(i,2,top2) {
		calc(vec[i-1],vec[i]);
		ret+=vec[i].ans;
	}
	int gt=st[top1];
	while (top2) {
		int i=st[top1--];
		p[i]=vec[top2--];
		link(hd,i);
	}
	gt=nxt[gt];
	while (1) {
        if (gt==tl) break;
        int g0=p[gt].g0,g1=p[gt].g1;
        ret-=p[gt].ans;
        calc(p[pre[gt]],p[gt]);
        ret+=p[gt].ans;
        if (g0==p[gt].g0&&g1==p[gt].g1) break;
        gt=nxt[gt];
	}
//    out();
	return ret;
}

inline ll work(int l,int r) {
//    printf("work:%d %d\n",l,r);
	cnt=0;xL=l;
	int now=l;
	p[++cnt]={l,l,0,1,0};
	while (1) {
		int nxt=R[now];
		if (nxt==now) break;
		p[++cnt]={now+1,nxt,0,0,0};
		now=nxt;
	}
	f(i,1,cnt) pre[i]=i-1,nxt[i]=i+1;
	hd=++cnt;tl=++cnt;
	pre[1]=hd;nxt[hd]=1;pre[hd]=0;
	nxt[cnt-2]=tl;pre[tl]=cnt-2;nxt[tl]=0;
	ll sum=0,ret=0;
	f(i,2,cnt) {
		calc(p[i-1],p[i]);
		sum+=p[i].ans;
	}
//	puts("calc:ok");
//	out();
	ret+=sum;
	f(i,l+1,r) {
	    sum+=update();
	    ret+=sum;
//	    printf("%lld\n",sum);
	}
	return ret;
}

inline void solve() {
	read(n);readl(m);
	f(i,1,n) readl(a[i]);
	get_LR();
//	f(i,1,n) printf("%d %d\n",L[i],R[i]);
	int lst=1;ll ans=0;
	f(i,2,n) if (L[i]==i) ans+=work(lst,i-1),lst=i;
	ans+=work(lst,n);
	printf("%lld\n",ans);
}

signed main() {
    freopen("migrate3.in","r",stdin);
//    freopen("test.out","w",stdout);
	int C,T;read(C);read(T);
	while (T--) solve();
	return 0;
}


15:34 n^2
16:16 I think brute is right
weihu mei ceng [L,R] g[r-1] g[r] ans
list to move ok
17:14 solved

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/

