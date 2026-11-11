#include<bits/stdc++.h>
using namespace std;
long long c,n,m,e,q,p=1,X,Y,ans;
long long w[500001],k[501],t[501],a[501];
vector<long long>v[500001];
struct D{long long u,v,z;}d[1000001];
struct R{long long x,y;};
vector<R>V[500001];
bool f[501];
void dfs(long long xx,long long cnt){
	if(xx==Y){ans=min(cnt,ans);return;}
	for(long long i=0;i<V[xx].size();i++){
		long long xxx=V[xx][i].x;
		if(f[xxx])continue;
		f[xxx]=true;
		dfs(xxx,cnt+V[xx][i].y);
		f[xxx]=false;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&e,&q);
	for(long long i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[j],&t[j]);
			if(j>1){
				d[p].u=a[j-1];d[p].v=a[j];
				d[p].z=t[j-1]+t[j];p++;
				d[p].u=a[j];d[p].v=a[j-1];
				d[p].z=t[j-1]+t[j];p++;
			}
		}
	}
	for(long long i=1;i<p;i++){
		if(V[d[i].u].empty())V[d[i].u].push_back({d[i].v,d[i].z});
		else{
			bool f=true;
			for(long long j=0;j<V[d[i].u].size();j++){
				if(V[d[i].u][j].x==d[i].v){
					f=false;
					V[d[i].u][j].y=min(V[d[i].u][j].y,d[i].z);
				}
			}
			if(f)V[d[i].u].push_back({d[i].v,d[i].z});
		}
		if(V[d[i].v].empty())V[d[i].v].push_back({d[i].u,d[i].z});
		else{
			bool f=true;
			for(long long j=0;j<V[d[i].v].size();j++){
				if(V[d[i].v][j].x==d[i].u){
					f=false;
					V[d[i].v][j].y=min(V[d[i].v][j].y,d[i].z);
				}
			}
			if(f)V[d[i].v].push_back({d[i].u,d[i].z});
		}
	}
	for(long long i=1;i<=q;i++){
		scanf("%lld%lld",&X,&Y);
		ans=1e16;f[X]=true;
		dfs(X,0);
		printf("%lld\n",ans+w[X]+w[Y]);
		memset(f,false,sizeof(f));
	}
	return 0;
} 
