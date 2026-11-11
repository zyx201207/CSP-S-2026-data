#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=1e3+5;
typedef pair<int,int> pii;
const pii oo=make_pair(N,0);
pii tr[N<<2],ly[N<<2];
ll x[N],d;
int n,nxt[N];
pii min(pii a,pii b){
	if(a.first==b.first)return make_pair(a.first,a.second+b.second);
	if(a.first<b.first)return a;
	return b; 
}
void build(int u,int l,int r){
	ly[u]=tr[u]=oo;
	if(l==r)return;
	int mid((l+r)>>1);
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
}
void pushdown(int u){
	if(ly[u]!=oo){
		tr[u<<1|1]=min(tr[u<<1|1],ly[u]);
		tr[u<<1]=min(tr[u<<1],ly[u]);
		ly[u<<1]=min(ly[u<<1],ly[u]);
		ly[u<<1|1]=min(ly[u<<1|1],ly[u]);
		ly[u]=oo;
	}
}
void update(int u,int l,int r,int s,int t,pii k){
	if(s<=l&&r<=t){
		tr[u]=min(tr[u],k);
		ly[u]=min(ly[u],k);
		return;
	}
	pushdown(u);
	int mid((l+r)>>1);
	if(s<=mid)update(u<<1,l,mid,s,t,k);
	if(t>mid)update(u<<1|1,mid+1,r,s,t,k);
	tr[u]=min(tr[u<<1],tr[u<<1|1]);
}
pii query(int u,int l,int r,int s){
	if(l==r)return tr[u];
	pushdown(u);
	int mid((l+r)>>1);
	if(s<=mid)return query(u<<1,l,mid,s);
	return query(u<<1|1,mid+1,r,s);
}
void work(){
	memset(nxt,0,sizeof nxt);
	memset(tr,0,sizeof tr);
	cin>>n>>d;
    for(int i=1;i<=n;++i)
    cin>>x[i];
    int lst=1;
    for(int i=1;i<=n;++i){
    	while(x[i]-x[lst]>d&&lst<=i){
    		nxt[lst]=i-1;
    		++lst;
		}
	}
	while(lst<=n)nxt[lst++]=n;
    int ans=0;
    for(int i=1;i<=n;++i){//Ã¶¾Ù¿ªÍ· 
    	build(1,1,n);
    	update(1,1,n,i,i,make_pair(0,1));
		for(int j=i;j<=n;++j){
			pii t=query(1,1,n,j);
			int w=t.first,ct=t.second;
			if(ct==2)++ans;
			update(1,1,n,j+1,nxt[j],make_pair(w+1,ct)); 
		} 
	}
	cout<<ans<<"\n";
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,T;
    cin>>c>>T;
    while(T--)work();
}

