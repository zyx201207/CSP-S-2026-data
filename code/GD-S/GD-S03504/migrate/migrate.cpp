#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int c,t,n,d,x[N],ans;
int to[2*N],nxt[2*N],head[N],ecnt;
void add(int u,int v){
	to[++ecnt]=v,nxt[ecnt]=head[u],head[u]=ecnt;
	to[++ecnt]=u,nxt[ecnt]=head[v],head[v]=ecnt;
} 
int dis[N],cnt[N];
queue<int> q;
signed main(){
	freopen("migrate4.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		ecnt=0;memset(head,0,sizeof head);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(abs(x[i]-x[j])<=d)
					add(i,j);
		ans=0;
		for(int st=1;st<n;st++){
			q.push(st);
			memset(dis,0x3f,sizeof dis);
			memset(cnt,0,sizeof cnt);
			dis[st]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=head[u];i;i=nxt[i]){
					int v=to[i];
					if(dis[u]+1<=dis[v]){
						q.push(v);
						if(dis[u]+1<dis[v])
							cnt[v]=0;
						cnt[v]++;
						dis[v]=dis[u]+1;
					}
				}
			}
			for(int i=st+1;i<=n;i++)
				if(cnt[i]==2)
					ans++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

