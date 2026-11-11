#include <bits/stdc++.h>
#define int long long
#define gc getchar
#define ls p << 1
#define rs p << 1 | 1
#define endl '\n'
using namespace std;

int Miku(){
	int k = 0,f = 1,c = gc();
	for (;!isdigit(c);c = gc()) if (c == '-') f = -1;
	for (;isdigit(c);c = gc()) k = k * 10 + (c ^ 48);
	return k * f;
}

const int N = 2e5+5;
int n,m,a[N],op,x,y,k;
struct Tree{
	int l,r,s,v;
}t[N << 2];

void pushup(int p){
	t[p].s = t[ls].s + t[rs].s;
	return ;
}
void pushdown(int p){
	if (t[p].v){
		t[ls].s += (t[ls].r - t[ls].l + 1) * t[p].v;
		t[rs].s += (t[rs].r - t[rs].l + 1) * t[p].v;
		t[ls].v += t[p].v;
		t[rs].v += t[p].v;
		t[p].v = 0;
	}
	return ;
}
void build(int p,int l,int r){
	t[p] = {l,r,0,0};
	if (l == r){
		t[p].s = a[l];
		return ;
	}
	int m = (l + r) >> 1;
	build(ls,l,m);
	build(rs,m+1,r);
	pushup(p);
	return ;
}
void change(int p,int x,int y,int k){
	if (x <= t[p].l && t[p].r <= y){
		t[p].s += (t[p].r - t[p].l + 1) * k;
		t[p].v += k;
		return ;
	}
	int m = (t[p].l + t[p].r) >> 1;
	pushdown(p);
	if (x <= m) change(ls,x,y,k);
	if (y > m) change(rs,x,y,k);
	pushup(p);
	return ;
}
int query(int p,int x,int y){
	if (x <= t[p].l && t[p].r <= y) return t[p].s;
	int m = (t[p].l + t[p].r) >> 1,re = 0;
	pushdown(p);
	if (x <= m) re += query(ls,x,y);
	if (y > m) re += query(rs,x,y);
	return re;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	n = Miku(); m = Miku();
	for (int i = 1;i <= n;i++) a[i] = Miku();
	build(1,1,n);
	while (m--){
		op = Miku(); x = Miku(); y = Miku();
		if (op == 1){
			k = Miku();
			change(1,x,y,k);
		}else cout << query(1,x,y) << endl;
	}
	
	return 0;
}
