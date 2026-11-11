#include<bits/stdc++.h>
using namespace std;
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
#define REP(i,x,y,z) for(int i=x;i>=y;i-=z)
void rd(int &x){
	int f=1;x=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+(c-'0'),c=getchar();
	x*=f;
}const int N=2e6+10;
int n,kkk,ans=1e8,a[N],k[N];bool vis[N];
vector<int>e[N];
void bbfs(int fi,int x){
	queue<int>q;q.push(fi);while(!q.empty()){
		int f=q.front();q.pop();
		vis[f]=true;for(int i=0;i<e[f].size();i++){
			int y=e[f][i];if(vis[y]||((1<<(y-1))&x)==0)continue;
			q.push(y);
		}
	}
}void bfs(int x){
	int res=0;FOR(i,1,n,1)vis[i]=false,k[i]=-1;
	queue<int>q;FOR(i,1,n,1)if((1<<(i-1))&x)q.push(i),k[i]=0;
	while(!q.empty()){
		int f=q.front();q.pop();
		vis[f]=true;for(int i=0;i<e[f].size();i++){
			int y=e[f][i];if(vis[y])continue;
			k[y]=k[f]+1;q.push(y);res=max(res,k[y]);
		}
	}ans=min(ans,res);
}bool check(int x){
	int cnt=0;FOR(i,1,n,1)vis[i]=false;
	FOR(i,1,n,1)if(!vis[i]&&(x&(1<<(i-1))))bbfs(i,x),cnt++;
	return cnt>2;
}void solve(){
	FOR(i,1,n,1)e[i].clear();
	rd(n),rd(kkk);FOR(i,1,n-1,1){int x,y;rd(x),rd(y);e[x].push_back(y),e[y].push_back(x);}
	FOR(i,1,(1<<n)-1,1){
		int cnt=0;FOR(j,1,n,1){
			int ll=(1<<(j-1));
			if(ll&i)cnt++;
		}if(cnt!=kkk)continue;
		if(check(i))continue;
		bfs(i);
	}cout<<ans<<"\n";ans=1e8;
}signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int C,_;rd(C),rd(_);while(_--)solve();
	return 0;
}