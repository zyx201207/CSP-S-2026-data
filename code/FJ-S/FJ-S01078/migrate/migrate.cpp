#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> PII;

ll read() {
	ll n=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		n=(n<<1)+(n<<3)+ch-'0';
		ch=getchar();
	}
	if(f==1) return n;
	return -n;
}

void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)+'0');
}

//========================================//

const int N=2e6+7;

int n,c;
ll d;
ll x[N];
ll ans;

//========================================//

int lower(ll a) { // <
	if(x[1]>=a) return 0;
	int t=lower_bound(x+1,x+1+n,a)-x-1;
	return t;
}

int lower2(ll a) { // <=
	if(x[1]>a) return 0;
	int t=upper_bound(x+1,x+1+n,a)-x-1;
	return t;
}

int upper(ll a) { // >
	if(x[n]<=a) return n+1;
	int t=lower2(a);
	return t+1;
}

int upper2(ll a) { // >=
	if(x[n]<a) return n+1;
	int t=lower(a);
	return t+1;
}

//========================================//

ll f[N],g[N];
ll pref[N],preg[N];

void init_fg() {
	f[1]=1;
	for(int i=2;i<n;i++) {
		f[i]=1;
		int t=upper2(x[i]-d);
		if(t==i) continue;
		if(lower2(x[t]+d)!=i) continue;
		int tt=lower(x[i+1]-d);
		f[i]+=tt-t+f[t];
	}
//	for(int i=1;i<=n;i++) 
//		cout<<f[i]<<" "; cout<<endl;
	for(int i=1;i<=n;i++) 
		pref[i]=pref[i-1]+f[i];
	g[n]=1;
	for(int i=n-1;i>=2;i--) {
		g[i]=1;
		int t=lower2(x[i]+d);
		if(t==i) continue;
		if(upper2(x[t]-d)!=i) continue;
		int tt=upper(x[i-1]+d);
		g[i]+=t-tt+g[t];
	}
//	cout<<"g: ";
//	for(int i=1;i<=n;i++) 
//		cout<<g[i]<<" "; cout<<endl;
	for(int i=1;i<=n;i++) 
		preg[i]=preg[i-1]+g[i];
}

//========================================//

void Solve() {
	if(n<=3) {
		write(0);
		puts("");
		return;
	}
	ll dec=x[2]-x[1];
	if(d<2*dec) {
		write(0);
		puts("");
		return;
	}
	ll m=d/dec;
	ll s=max(0ll,n-(2*m-1));
	write(s),puts("");
}

//========================================//

void input() {
	n=read(); d=read();
	for(int i=1;i<=n;i++) 
		x[i]=read();
}

void work() {
	if(c==11 || c==12) {
		Solve();
		return;
	}
	init_fg();
	ans=0;
	for(int i=2,j=3;j<n;i++,j++) {
		int l1=upper2(x[j]-d);
		int r1=lower(x[j+1]-d);
		r1=min(r1,i-1);
		int l2=upper(x[i-1]+d);
		int r2=lower2(x[i]+d);
		l2=max(l2,j+1);
		if(l1>r1 || l2>r2) continue;
//		cout<<x[i]<<","<<x[j]<<":     ";
//		cout<<x[l1]<<","<<x[r1]<<"  ,  "<<x[l2]<<","<<x[r2]<<endl;
		ans+=(r2-l2+g[r2])*(r1-l1+f[l1]);
	}
	write(ans),puts("");
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	int T=read();
	while(T--) {
		input();
		work();
	}
	return 0;
}
