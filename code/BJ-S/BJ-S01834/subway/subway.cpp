#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x1,y,ans,now,minans=2e9;
//输入的第一行包含五个非负整数 c, n, m, d, q,分别表示测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。特别地,若 c = 0,则
//该测试点为样例。
long long w[500005];
long long k[534],vis[500005];
struct mashell_maximiser{
long long a=0,t=0;
}a[534][20005];
vector<long long>z[500005];
void dfs(long long x){
//	cout<<x<<" "<<now<<" "<<ans<<endl;
	if(x==y){
		for(long long i=1;i<=k[now];i++){
			if(a[now][i].a==x){
				ans+=a[now][i].t;
				minans=min(minans,ans);
				ans-=a[now][i].t;
			}
		}
		return;
	}
	vis[x]++;
	if(vis[x]==2){
		vis[x]--;
		return;
	}
	long long ni;
	for(long long i=1;i<=k[now];i++){
		if(a[now][i].a==x){
			ni=i;
		}
	}
	for(long long y:z[x]){
		long long pi;
		for(long long i=1;i<=k[y];i++){
			if(a[y][i].a==x){
				pi=i;
			}
		}
		if(!vis[a[y][pi-1].a]&&pi>1){
			long long backnow=now;
			if(y==now){
				;
			}
			else{
				ans+=a[now][ni].t;
				ans+=a[y][pi].t;
			}
			now=y;
			dfs(a[y][pi-1].a);
			now=backnow;
			if(y==now){
				;
			}
			else{
				ans-=a[now][ni].t;
				ans-=a[y][pi].t;
			}
		}
		if(!vis[a[y][pi+1].a]&&pi<k[y]){
			long long backnow=now;
			if(y==now){
				;
			}
			else{
				ans+=a[now][ni].t;
				ans+=a[y][pi].t;
			}
			now=y;
			dfs(a[y][pi+1].a);
			now=backnow;
			if(y==now){
				;
			}
			else{
				ans-=a[now][ni].t;
				ans-=a[y][pi].t;
			}
		}
	}
	vis[x]--;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
//	cout<<"mashell maximiser"<<endl;
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j].a>>a[i][j].t;
			z[a[i][j].a].push_back(i);
		}
//	cout<<"mashell maximiser"<<endl;
	}
//	cout<<"mashell maximiser"<<endl;
	for(long long i=1;i<=q;i++){
//	cout<<i<<endl;
		cin>>x1>>y;
		ans=0;
		minans=2e9;
		ans+=w[x1];
		ans+=w[y];
		now=509;
		dfs(x1);
		cout<<minans<<endl;;
	}
	return 0;
}
