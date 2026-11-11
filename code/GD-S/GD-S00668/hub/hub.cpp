#include<bits/stdc++.h>
using namespace std;
/*
#include<bits/stdc++.h>
#define lc u << 1
#define rc u << 1 | 1
using namespace std;
int n,m,q;
int a[1 << 10];
struct TR{
	int sum,lazy;
	int l,r;
}tr[1 << 12];
void pushup(int u){
	tr[u].sum = tr[lc].sum + tr[rc].sum;
}
void pushdown(int u){
	if(tr[u].lazy){
		tr[lc].sum += tr[u].lazy * (tr[lc].r - tr[lc].l + 1);
		tr[lc].lazy = tr[u].lazy;
		tr[rc].sum += tr[u].lazy * (tr[rc].r - tr[rc].l + 1);
		tr[rc].lazy += tr[u].lazy;
		tr[u].lazy = 0;
	}
}
void build(int u,int l,int r){
	tr[u] = {a[l],0,l,r};
	if(l == r) return ;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	pushup(u);
}
void change(int u,int x,int y,int k){
	if(x <= tr[u].l && tr[u].r <= y){
		tr[u].sum += k * (tr[u].r - tr[u].l + 1);
		tr[u].lazy = k;
		return ;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if(x <= mid) change(lc,x,y,k);
	if(mid < y) change(rc,x,y,k);
	pushup(u);
}
int query(int u,int x,int y){
	if(x <= tr[u].l && tr[u].r <= y)
		return tr[u].sum;
	pushdown(u);
	int ans = 0;
	int mid = tr[u].l + tr[u].r >> 1;
	if(x <= mid) ans += query(lc,x,y);
	if(mid < y) ans += query(rc,x,y);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	build(1,1,n);
	for(int i = 1,x,y,k; i <= m; i++){
		cin>>x>>y>>k;
		change(1,x,y,k);
	}
	for(int i = 1,x,y; i <= q; i++){
		cin>>x>>y;
		cout<<query(1,x,y)<<'\n';
	}
	return 0;
}
*/ 
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	cin>>c>>t;
	while(t--){
		cout<<rand() % 2000000000000<<endl;
	}
	return 0;
}
