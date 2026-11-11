#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],vis[2000005],ct[200005],ans;
vector <long long> g[2000005];
unordered_map <int, unordered_map<int,int> > p;
void solve(int x){
	queue <long long > q,sp;
	memset(vis,-1,sizeof(vis));
	memset(ct,0,sizeof(ct));
	q.push(x); sp.push(0);
	vis[x]=0;
	while(!q.empty()){
		int fx=q.front(),fy=sp.front();
		q.pop(); sp.pop();
		for(auto i: g[fx]){
			if(vis[i]!=-1){
				if(vis[i]==fy+1&&vis[i]!=0) ct[i]++;
				continue;
			}
			vis[i]=fy+1;
			ct[i]++; 
			q.push(i);
			sp.push(fy+1);
		}
	}
	for(int i=1;i<=n;i++){
		if(ct[i]==2&&p[x][i]==0){
			p[x][i]=1;
			p[i][x]=1;
			ans++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		p.clear();
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d) break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			solve(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
