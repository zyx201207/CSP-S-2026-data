// 3:00
// 3:37

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define siz(x) ((int)(x).size())
#define L(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,r,l) for(int i=(r);i>=(l);i--)
#define ve(x) vector<x>
#define x first
#define y second
#define me(x,v) memset(x,v,sizeof(x))
#define wr(...) printf(__VA_ARGS__)

#define ast(x) assert(x)

using sint =signed;
using ll =long long;

char gc() {
	return getchar();
}
void pc(char c) {
	putchar(c);
}
int rd() {
	int sgn=0,ret=0,c=0;
	while(c<'0'||c>'9') {
		sgn|=(c=='-');
		c=gc();
	}
	while(c>='0'&&c<='9') {
		ret=ret*10+c-'0';
		c=gc();
	}
	return sgn?-ret:ret;
}

void chkmin(int& x,int y) {
	if(x>y) {
		x=y;
	}
}

constexpr int N=2e6+7;

int a[N];
int nxt[N],lst[N];
int n,d;

int find(int l,int r,int x) {
	int ans=l;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(a[mid]<=x) {
			ans=mid,l=mid+1;
		} else {
			r=mid-1;
		}
	}
	return ans;
}

struct E {
	int x,v1,v2;
};

E qu[2*N],;
int head,tail;

void fw() {
	int x=qu[head].x;
	qu[tail]=qu[head];
	qu[tail].x=lst[x];
	head++;
}

void task() {
	head=tail=0;
	n=rd(),d=rd();
	L(i,1,n) {
		a[i]=rd();
	}
	nxt[n]=n;
	R(i,n-1,1) {
		nxt[i]=find(i,nxt[i+1],a[i]+d);
	}
	R(i,n,1) {
		lst[nxt[i]]=i;
	}
	int ans=0;
	R(i,n,1) {
		int cur=0;
		while(head<tail&&lst[qu[head].x]>nxt[i]) {
			fw();
		}
		if(head<tail&&lst[qu[head].x]==nxt[i]){
			cur+=qu[head].v2; 
		}
		if(head<tail&&qu[head].x==nxt[i]-1) {
			cur+=qu[head].v1;
			qu[head].v2=qu[head].v1;
//			fw();
		}
		L(j,head,tail-1){
			qu[j].v1=qu[j].v2=0;
		}
		
	}
}

sint main() {
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);

	rd();
	int t=rd();
	while(t--) {
		task();
	}

	return 0;
}
