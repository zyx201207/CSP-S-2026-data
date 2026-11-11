//毕节梁才学校
//罗悦辉
//GZ-S00393 
#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;

int to[40];
int nt[40];
int h[20];
int idx;

void add(int x,int y){
	to[idx]=y;
	nt[idx]=h[x];
	h[x]=idx;
	idx++;
}

int a[40];
bool v[40];

void dfs(int u,int fa){
	v[u]=true;
	for(int i=h[u];i!=-1;i=nt[i]){
		int j=to[i];
		if(v[j]||j==fa) continue;
		for(int vv=1;vv<=k;vv++) {
			if(a[vv]==j&&!v[j]) v[j]=true,dfs(j,u); 
		}
	}
}

int q[310];
int mi=0x3f3f3f3f;
int tt=-1,hh=0;
int d[310];
void bfs(){
	int ans=0;
	memset(d,0x3f,sizeof(d));
	tt=-1,hh=0;
	for(int i=1;i<=k;i++) q[++tt]=a[i],d[a[i]]=0;
	while(hh<=tt){
		int t=q[hh++];
		for(int i=h[t];i!=-1;i=nt[i]){
			int j=to[i];
			if(d[j]==0x3f3f3f3f) d[j]=d[t]+1,q[++tt]=j,ans=max(d[j],ans);
		}
	}
	mi=min(mi,ans);
}

void dfs_zhao(int u,int now){
	if(now>k) {
//		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//		puts("");
		int cnt=0;
		memset(v,0,sizeof(v));
		for(int i=1;i<=k;i++) {
			if(!v[a[i]]) dfs(a[i],-1),cnt++;
		}
		if(cnt>2) return ;
		bfs();
		return ;
	}
	for(int i=u;i<=n;i++){
		a[now]=i;
		dfs_zhao(i+1,now+1);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	
	while(t--){
		mi=0x3f3f3f3f;
		memset(h,-1,sizeof(h));
		idx=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y),add(y,x);
		}
		dfs_zhao(1,1);
		printf("%d\n",mi);
	}
	
	
	return 0;
}
