#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mx=0x3f3f3f3f3f3f3f3f;
int x[2000005],n,d,b[2000005],ans,dis[2000005];
void dfs(int bg,int u,int sum){
	int j=bg,i=u+1;
	int now=0;
	for(;i<=n&&x[i]-x[u]<=d;i++){
		while(x[i]-x[j]>d){
			sum-=b[j];
			j++;
		}
		b[i]=(sum>2?3:sum);
		if(b[i]==2) ans++;
		//cout<<i<<" "<<b[i]<<endl;
		now+=b[i];
	}
	i--;
	//cout<<bg<<" "<<u<<" "<<u+1<<" "<<i<<endl; 
	if(i>u) dfs(u+1,i,now);
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",x+i);
		ans=0;
		for(int i=1;i<=n;i++){
			b[i]=1;
			dfs(i,i,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
