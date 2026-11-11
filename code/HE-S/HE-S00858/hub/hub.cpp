#include<bits/stdc++.h>
#define ll long long
#define enter putchar('\n');
#define space putchar(' ');
using namespace std;
const int N=1e3+5,inf=0x3f3f3f3f;
ll read();
void write(ll x);
ll ans,n,k,mp[N][N];
void dfs(queue<int> q,int cnt,int now){
	if(cnt==k){
		vector<int> ve;
		int flag[N]={},bi=0;
		while(!q.empty()){
			ve.push_back(q.front());
			q.pop();
		}
		for(int i=0;i<k;i++){
			if(!flag[ve[i]])
			for(int j=0;j<k;j++){
				if(i!=j&&mp[ve[i]][ve[j]]==1&&flag[ve[j]]){
					flag[ve[i]]=flag[ve[j]];
					break;
				}
			}
			if(!flag[ve[i]]) flag[ve[i]]=++bi;
			if(bi>2) return;
		}
		ll mx=0;
		for(int i=1;i<=n;i++){
			ll mn=inf;
			for(int j=0;j<k;j++){
				mn=min(mp[i][ve[j]],mn);
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
		return;
	}
	if(now>n) return;
	dfs(q,cnt,now+1);
	q.push(now);
	dfs(q,cnt+1,now+1);
}
void solve(){
	ans=inf;
	n=read();
	k=read();
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		mp[u][v]=1;
		mp[v][u]=1;
	}
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			for(int k=u;k<=v;k++){
				mp[u][v]=mp[v][u]=min(mp[u][v],mp[u][k]+mp[k][v]);
			}
		}
	}
	queue<int> q;
	dfs(q,0,0);
	write(ans);
	enter;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    int c,T;
    c=read();
    T=read();
    while(T--) solve();
	return 0;
}
ll read(){
	ll op=1,cnt=0;
	int c;
	c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') op*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return op*cnt;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
