#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
const int maxm=9e4+5;
const int maxx=3e2+5;
int c, t, n, d, a[maxn], ld[maxn], rd[maxn], dt, ans;
int cnt, lbb[maxm<<1], zh[maxx][maxx], cs[maxx][maxx], bj[maxx][maxx];
struct nn{
	int to, nxt, ww;
}gra[maxn<<1];
void add(int u, int v, int w){
	gra[++cnt]={v,lbb[u],w};
	lbb[u]=cnt;
}
struct tt{
	int xid, dis;
}lb;
priority_queue<tt> q;
bool operator<(tt t1, tt t2){
	return t1.dis>t2.dis;
}
void dij(int s){
	zh[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		lb=q.top();
		q.pop();
		if(bj[s][lb.xid]==1) continue;
		bj[s][lb.xid]=1;
		for(int i=lbb[lb.xid];i;i=gra[i].nxt){
			int v=gra[i].to;
			if(zh[s][v]>zh[s][lb.xid]+gra[i].ww){
				cs[s][v]=cs[s][lb.xid];
				zh[s][v]=zh[s][lb.xid]+gra[i].ww;
				q.push({v,zh[s][v]});
			}else if(zh[s][v]==zh[s][lb.xid]+gra[i].ww){
				cs[s][v]+=cs[s][lb.xid];
				q.push({v,zh[s][v]});
			}
		}
	}
}
int efl(int i){
	int L=i, R=n, mid=0, re=i;
	while(L<=R){
		mid=(L+R)>>1;
		if(a[mid]-a[i]<=d){
			L=mid+1;
			re=mid;
		}else{
			R=mid-1;
		}
	}
	return re;
}
int efr(int i){
	int L=1, R=i, mid=0, re=i;
	while(L<=R){
		mid=(L+R)>>1;
		if(a[i]-a[mid]<=d){
			R=mid-1;
			re=mid;
		}else{
			L=mid+1;
		}
	}
	return re;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			zh[i][j]=1e18;
			bj[i][j]=0;
			cs[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		rd[i]=efl(i);
		ld[i]=efr(i);
	}
	for(int i=1;i<=n;i++){
		int lb=0;
		for(int j=i;j<n;j=rd[j]){
			lb++;
			for(int k=j;k<=rd[j];k++){
				add(i,k,lb);
			}
		}
		lb=0;
		for(int j=i;j>1;j=ld[j]){
			lb++;
			for(int k=j;k>=ld[j];k--){
				add(i,k,lb);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cs[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
T:O(n)
M:
*/
