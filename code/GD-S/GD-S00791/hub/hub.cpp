#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
typedef pair<int,int> pii;
const int N=1e6+50;
int c,T,n,k;
int head[N],tot=1;
struct Edge{
	int to,nxt;
}e[N*2];
void add(int u,int v){
	e[++tot]={v,head[u]},head[u]=tot;
}
void dfs(int u,int fa,int d,int cur,int&cnt){
	if(cur<=0)++cnt;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,u,d,cur<=0?d:cur-1,cnt); 
	}
}
bool check(int x){
	int cnt=0;
	dfs(1,0,x,x,cnt);
	return cnt<=k;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		tot=1,memset(e,0,sizeof(e)),memset(head,0,sizeof(head));
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;add(u,v);add(v,u);
		}
		int l=0,r=n*n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
} 
