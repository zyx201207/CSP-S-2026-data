#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> PII;

int read() {
	int n=0,f=1;
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

void write(int x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)+'0');
}

//========================================//

const int N=2e6+7,M=N<<1;

int c;
int n,k;

//========================================//

int h[N];
int to[M],nxt[M];
int tot;

void add(int a,int b) {
	to[tot]=b,nxt[tot]=h[a],h[a]=tot++;
}

//========================================//

void Solve() {
	if(k==n) {
		write(0);
		puts("");
		return;
	}
	int m=(n-1)/2;
	if(k>=m) {
		write(1);
		puts("");
		return;
	}
	if((m-k+3)%4==0) {
		write((m-k+3)/4);
		puts("");
		return;
	}
	write((m-k+3)/4+1);
	puts("");
}

//========================================//

void input() {
	n=read(),k=read();
	for(int i=1;i<=n;i++) h[i]=-1; tot=0;
	for(int i=1;i<n;i++) {
		int u,v;
		u=read(),v=read();
		add(u,v),add(v,u);
	}
}

void work() {
	if(c==13 || c==14) {
		Solve();
		return;
	}
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	int T=read();
	while(T--) {
		input();
		work();
	}
	return 0;
}
