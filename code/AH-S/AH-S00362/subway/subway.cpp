#include<bits/stdc++.h>
using namespace std;
int const N=1e4+6370;
long long c,d,q,n,m,a[N][N],cnt,u,v,ans=INT_MAX;
vector<int> r[N];
int che[N];
void dfs(long long x,long long y,long long s){
	che[x]=1;
	if(x==y){
		ans=min(s,ans);
		return;
	}
	int l=r[x].size();
	for(int i=0;i<l;i++){
		if(!che[r[x][i]]){
			dfs(r[x][i],y,s+a[x][r[x][i]]);
			che[r[x][i]]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	cnt=m;
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i][++cnt]);
		a[cnt][i]=a[i][cnt];
		r[i].push_back(cnt);
		r[cnt].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		++cnt;
		for(int j=1;j<=k;j++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			a[x+m][cnt]=y,a[cnt][x+m]=y;
			r[x+m].push_back(cnt),r[cnt].push_back(x+m);
		}
	}
	while(q--){
		ans=INT_MAX;
		for(int i=1;i<=cnt;i++)che[i]=0;
		scanf("%lld%lld",&u,&v);
		dfs(u,v,0);
		printf("%lld\n",ans);
	}
	return 0;
}
