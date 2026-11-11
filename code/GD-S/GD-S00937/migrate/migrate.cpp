#include<bits/stdc++.h>
#include<queue>
using namespace std;

const int MAXN=2e6+10;

struct node{
	int id,cnt;
};

int c,t,n,ans;
long long d;
long long x[MAXN];
int l[MAXN],vis[MAXN];

queue<node> q;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--){
		scanf("%d%lld",&n,&d);ans=0;
		for (int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (x[j]-x[i]>d) break;
				l[i]=j;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				q.push({i,0});int res=MAXN,c=0;
				for (int k=i;k<=j;k++)
					vis[k]=MAXN;
				while (!q.empty()){
					int u=q.front().id,now=q.front().cnt;q.pop();
					if (now>vis[u]) continue;
					vis[u]=now;
					if (u==j){
						if (now<res) res=now,c=1;
						else if (now==res) c++;
						continue;
					}
					for (int k=u+1;k<=l[u];k++)
						q.push({k,now+1});
				}
				if (c==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
