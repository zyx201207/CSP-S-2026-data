#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[500001][501],k[505],cnt=0,head[500003],a;
long long ans=2e18;
bool vis[500003];
struct Node{
	int to,next,x;
}s[1000003];
struct No{
	int h,nu;
	long long an;
	bool operator < (No glx)const{return an<glx.an;}
};
priority_queue<No> q1;
void add(int u,int v,int x){
	s[++cnt].to=v;
	s[cnt].x=x;
	s[cnt].next=head[u];
	head[u]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int l=0;
		for(int j=1;j<=k[i];j++){
			scanf("%d",&a);
			scanf("%d",&t[i][a]);
			if(j>1){
				add(l,a,i);
				add(a,l,i);
			}
			l=a;
		}
	}
	while(q--){
		int s1,t1;
		ans=2e18;
		for(int i=1;i<=m;i++) vis[i]=0;
		scanf("%d%d",&s1,&t1);
		for(int i=head[s1];i;i=s[i].next){
			q1.emplace((No){s[i].to,s[i].x,(long long) w[i]+t[s[i].x][s1]});
		}
		vis[s1]=1;
		while(!q1.empty()){
			No u=q1.top();
			vis[u.h]=1;
			q1.pop();
			if(u.h==t1){
				ans=min(u.an+t[u.nu][u.h]+w[u.h],ans);
				continue;
			}
			for(int i=head[u.h];i;i=s[i].next){
				if(vis[s[i].to]&&s[i].to!=t1) continue;
				if(s[i].x!=u.nu) q1.emplace((No){s[i].to,s[i].x,u.an+t[u.nu][u.h]+t[s[i].x][u.h]});
				else q1.emplace((No){s[i].to,u.nu,u.an});
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
