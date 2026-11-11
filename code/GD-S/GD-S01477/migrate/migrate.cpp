#include<bits/stdc++.h>
#define lc(p) ((p)<<1)
#define rc(p) ((p)<<1|1)
using namespace std;
typedef long long ll;
int C,T,n;
ll d,a[2000010];
int nxt[2000010],pre[2000010];
vector<int> G1[2000010],G2[2000010],rt1,rt2;
int vis[2000010],cnt,R,sz[2000010],dfn[2000010],tsp;
ll ans;
void dfs22(int x){
	dfn[x]=++tsp;
	sz[x]=1;
	for(int y:G2[x]){
		dfs22(y);
		sz[x]+=sz[y];
	}
} 
void dfs2(int x){
//	cout<<x<<" "<<cnt<<'\n';
	if(x+3<=R&&cnt==1)ans++;
	if(x<R&&vis[x-1]&&!vis[x])cnt++;
	for(int y:G2[x]){
		dfs2(y);
	}
	if(x<R&&vis[x-1]&&!vis[x])cnt--;
}
void solve(){
//	cout<<"now:"<<R<<'\n';
//	for(int j=1;j<=n;j++){
//		cout<<vis[j]<<" \n"[j==n];
//	}
	for(int rt:rt2){
		dfs2(rt);
	}
}
void dfs1(int x){
	R=x;
	solve();
	vis[x]=1;
	for(int y:G1[x]){
		dfs1(y);
	}
	vis[x]=0;
}
struct N{
	int mn,c,mn2,c2,la;
}tr[8000010];
void merge(N &t,N l,N r){
	t.mn=l.mn;
	t.c=l.c;
	t.mn2=l.mn2;
	t.c2=l.c2;
	if(r.mn<t.mn){
		t.mn2=t.mn,t.c2=t.c;
		t.mn=r.mn;t.c=r.c;
	}
	else if(r.mn==t.mn)t.c+=r.c;
	else if(r.mn<t.mn2){
		t.mn2=r.mn,t.c2=r.c;
	}
	else if(r.mn==t.mn2)t.c2+=r.c;
	if(r.mn2<t.mn2){
		t.mn2=r.mn2,t.c2=r.c2;
	}
	else if(r.mn2==t.mn2)t.c2+=r.c2;
}
void bt(int p,int l,int r){
	if(l==r){
		tr[p]={0,1,1000000000,0,0};
		return ;
	}
	int mid=(l+r)>>1;
	bt(lc(p),l,mid);
	bt(rc(p),mid+1,r);
	merge(tr[p],tr[lc(p)],tr[rc(p)]);
}
void pushdown(int p){
	if(tr[p].la){
		tr[lc(p)].mn+=tr[p].la;
		tr[lc(p)].mn2+=tr[p].la;
		tr[lc(p)].la+=tr[p].la;
		tr[rc(p)].mn+=tr[p].la;
		tr[rc(p)].mn2+=tr[p].la;
		tr[rc(p)].la+=tr[p].la;
		tr[p].la=0;
	}
}
void change(int p,int l,int r,int x,int y,int v){
	if(x>y)return ;
	if(l>=x&&r<=y){
		tr[p].mn+=v;
		tr[p].mn2+=v;
		tr[p].la+=v;
		return ;
	}
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)change(lc(p),l,mid,x,y,v);
	if(y>mid)change(rc(p),mid+1,r,x,y,v);
	merge(tr[p],tr[lc(p)],tr[rc(p)]);
}
void dfs11(int x){
//	cout<<x<<" ";
	vis[x]=1;
	if(vis[x-1]){
		change(1,1,n,dfn[x]+1,dfn[x]+sz[x]-1,-1);
	}
//	cout<<x<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<find(dfn[i])<<" \n"[i==n];
//	}
	if(tr[1].mn==1)ans+=tr[1].c;
	else if(tr[1].mn2==1)ans+=tr[1].c2;
	if(x<n&&!vis[x+1]){
//		cout<<dfn[x+1]+1<<" "<<dfn[x+1]+sz[x+1]-1<<'\n';
		change(1,1,n,dfn[x+1]+1,dfn[x+1]+sz[x+1]-1,1);
	}
//	cout<<6;
	for(int y:G1[x]){
		dfs11(y);
	}
	vis[x]=0;
	if(x<n&&!vis[x+1]){
		change(1,1,n,dfn[x+1]+1,dfn[x+1]+sz[x+1]-1,-1);
	}
	if(vis[x-1]){
		change(1,1,n,dfn[x]+1,dfn[x]+sz[x]-1,1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			G1[i].clear();
			G2[i].clear();
//			cout<<a[i]-a[i-1]<<" ";
		}
		nxt[0]=1;
		for(int i=1;i<=n;i++){
			nxt[i]=nxt[i-1];
			while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d)nxt[i]++;
		}
		pre[n+1]=n;
		for(int i=n;i;i--){
			pre[i]=pre[i+1];
			while(pre[i]>1&&a[i]-a[pre[i]-1]<=d)pre[i]--;
		} 
		rt1.clear();
		rt2.clear();
		for(int i=1;i<=n;i++){
			if(pre[i]!=i){
				G1[pre[i]].push_back(i);
//				cout<<"1:"<<pre[i]<<" "<<i<<'\n';
			}
			else rt1.push_back(i);
			if(nxt[i]!=i){
				G2[nxt[i]].push_back(i);
//				cout<<"2:"<<nxt[i]<<" "<<i<<'\n';
			}
			else rt2.push_back(i);
		}
		if(C<=10){
			ans=cnt=0;
			for(int rt:rt1){
				dfs1(rt);
			}
		}
		else{
			ans=tsp=0;
			for(int rt:rt2){
				dfs22(rt);
			}
	//		cout<<6;
			bt(1,1,n); 
			for(int rt:rt1){
				dfs11(rt);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4

0 1
10 3
0 3 6 8 10 11 12 13 15 18

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
5 3
-3 0 2 3 4
*/
