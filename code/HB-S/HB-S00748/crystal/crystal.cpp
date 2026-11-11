#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int w = 1,s = 0;
	char ch = getchar();
	while(ch<48||ch>57){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch>=48&&ch<=57){
		s = (s<<1)+(s<<3)+(ch^48);
		ch = getchar();
	}
	return w*s;
}

const int N = 5e5+10;

int n,m,tot,maxn = 0,a[N],cnt,tr[N<<2],tag[N<<2],dis[N];

struct node{
	int l,r,val;
}sec[N];

int ls(int p){
	return p<<1;
}

int rs(int p){
	return p<<1|1;
}

void push_up(int p){
	tr[p] = tr[ls(p)]+tr[rs(p)];
}

void f(int p,int l,int r,int k){
	tr[p] += (r-l+1)*k;
	tag[p] += k;
}

void push_down(int p,int l,int r){
	int mid = (l+r)>>1;
	f(ls(p),l,mid,tag[p]);
	f(rs(p),mid+1,r,tag[p]);
	tag[p] = 0;
}

void build(int p,int l,int r){
	if(l==r){
		tr[p] = dis[l];
		return;
	}
	int mid = (l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}

void update(int p,int l,int r,int s,int t,int k){
	if(s<=l&&r<=t){
		f(p,l,r,k);
		return;
	}
	int mid = (l+r)>>1;
	push_down(p,l,r);
	if(s<=mid)update(ls(p),l,mid,s,t,k);
	if(t>mid)update(rs(p),mid+1,r,s,t,k);
	push_up(p);
}

int query(int p,int l,int r,int s,int t){
	if(s<=l&&r<=t){
		return tr[p];
	}
	int mid = (l+r)>>1,res = 0;
	push_down(p,l,r);
	if(s<=mid)res += query(ls(p),l,mid,s,t);
	if(t>mid)res += query(rs(p),mid+1,r,s,t);
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;++i){
		a[i] = read();
	}
	sort(a+1,a+1+n);
	for(int i = 0;i < n;++i){
		if(a[i]!=a[i+1]||i==0){
			sec[cnt].r = i;
			cnt++;
			sec[cnt].l = i+1;
			sec[cnt].val = a[i+1];
		}
	}
	sec[cnt].r = n;
	maxn = sec[1].r-sec[1].l+1;
	maxn = max(maxn,0LL);
	for(int i = 2;i <= cnt;++i){
		int dist = sec[i].val-sec[i-1].val;
		update(1,1,n,1,sec[i].l-1,dist);
		int l1 = 1,r1 = sec[i].l-1;
		while(l1!=r1){
			int mid = (l1+r1)>>1,v = query(1,1,n,mid,sec[i].l-1);
			if(v>m){
				l1 = mid+1;
			}
			else{
				r1 = mid;
			}
		}
		int g = sec[i].l-l1;
		g = max(g,0LL);
		maxn = max(maxn,g+sec[i].r-sec[i].l+1);
	}
	cout<<maxn;
	return 0;
}