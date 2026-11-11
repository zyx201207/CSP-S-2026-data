#include<bits/stdc++.h>
using namespace std;
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
typedef long long ll;
const int N(2e6+5);
int n;
ll d,x[N];
struct node{
	int mn,cnt;
	node(){mn=1e9; cnt=-1;}
	inline bool empty(){return cnt==-1 || mn==1e9;}
}tr[N<<2],non;
node merge(node a,node b){
	if(a.empty()) return b;
	if(b.empty()) return a;
	node res;
	if(a.mn==b.mn) res.mn=a.mn,res.cnt=a.cnt+b.cnt;
	else if(a.mn<b.mn) res=a;
	else res=b;
	return res;
}
void build(int p,int pl,int pr){
	if(pl==pr){
		tr[p].mn=1e9;
		tr[p].cnt=-1;
		return ;
	}int mid(pl+((pr-pl)>>1));
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	tr[p]=merge(tr[ls(p)],tr[rs(p)]);
}
void modify(int p,int pl,int pr,int x,int mn,int cnt){
	if(pl==pr){
		tr[p].mn=mn;
		tr[p].cnt=cnt;
		return ;
	}int mid(pl+((pr-pl)>>1));
	if(x<=mid) modify(ls(p),pl,mid,x,mn,cnt);
	else modify(rs(p),mid+1,pr,x,mn,cnt);
	tr[p]=merge(tr[ls(p)],tr[rs(p)]);
}
node query(int p,int pl,int pr,int L,int R){
	if(L>R) return non;
	if(L<=pl && pr<=R) return tr[p];
	int mid(pl+((pr-pl)>>1)); node res;
	if(L<=mid) res=merge(res,query(ls(p),pl,mid,L,R));
	if(mid<R) res=merge(res,query(rs(p),mid+1,pr,L,R));
	return res;
}
node tmp;
ll ans(0);
void sol(){
	cin>>n>>d;
	for(int i(1);i<=n;++i) cin>>x[i];
	ans=0;
	for(int i(1);i<n;++i){
		build(1,i,n);
		modify(1,i,n,i,0,1);
		for(int j(i+1),pos;j<=n;++j){
			pos=lower_bound(x+1,x+n+1,x[j]-d)-x;
			tmp=query(1,i,n,pos,j-1);
			if(tmp.empty()) break ;
			modify(1,i,n,j,tmp.mn+1,tmp.cnt);
			if(tmp.cnt==2) ++ans;
		}
	}cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cs,T; cin>>cs>>T;
	for(;T;--T) sol();
	return 0;
}
