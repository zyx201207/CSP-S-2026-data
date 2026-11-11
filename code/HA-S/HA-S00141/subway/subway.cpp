#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q1;
int x,k,y,z;
int a[510005];
vector<int> ls[500605];
vector<long long> la[500605];
long long lu[505][50605];
int done[500605];
struct tree{
	int t;
	long long lon;
	friend bool operator <(tree x,tree y){
		return x.lon>y.lon;
	}
};
priority_queue <tree> q;
void duan(int t){
	q.push(tree{t+m,0});
	while(!q.empty()){
		tree u1=q.top();
		q.pop();
		int u=u1.t,lon=u1.lon;
		if(done[u]) continue;
		done[u]=1;
		for(int i=0;i<ls[u].size();i++){
			int v=ls[u][i];
			if(lu[t][v]>lu[t][u]+la[u][i]){
				lu[t][v]=lu[t][u]+la[u][i];
				q.push(tree{v,lu[t][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q1);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d %d",&x,&z);
			long long t=z;
			ls[x].push_back(i+m);
			ls[i+m].push_back(x);
			la[x].push_back(t);
			la[i+m].push_back(t);
		}
	}
	for(int i=m+1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			done[j]=0;
			lu[i-m][j]=1e17+7;
		}
		lu[i-m][i]=0;
		duan(i-m);
	}
	for(int i=1;i<=q1;i++){
		scanf("%d %d",&x,&y);
		long long ans=1e17+7,np;
		for(int j=1;j<=n;j++){
			np=lu[j][x]+lu[j][y];
			ans=min(ans,np);
		}
		ans+=a[x]+a[y];
		printf("%lld\n",ans);
	}
}
