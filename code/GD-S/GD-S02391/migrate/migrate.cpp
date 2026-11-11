#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int n,c,t,an=0;
long long x[N],d;
int find1(int ll){
	int r=n,l=ll,ans=ll;
	while(l<=r){
		int midd=(r+l)>>1;
		if(x[midd]-x[ll]>d) r=midd-1;
		else l=midd+1,ans=midd;
	}
	return ans;
}
int dfs(int u,int v,int maxstep,int stepnow){
	if(stepnow>maxstep) return 0;
	if(u==v) {
		an++;
		return 0;
	}
	int nn=find1(u);
	for(int i=u+1;i<=nn;i++){
		dfs(i,v,maxstep,stepnow+1);
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		long long ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int stepp=1,u=find1(i);
				while(u<j){
					stepp++;
					u=find1(u);
				}
				an=0;
				dfs(i,j,stepp,0);
				if(an==2) ans++;
			}
		}
		printf("%lld\n",ans);
    }
	return 0;
}
