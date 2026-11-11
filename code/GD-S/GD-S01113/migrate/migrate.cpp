#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long x[200005];
long long sum[200005];
long long ans;
long long num[200005];
void dfs(int l,int r,long long summ){
	if(summ>num[r]) return ;
	num[r]=summ;
	sum[r]++;
	for(int i=n;i>r;i--){
		if(x[i]-x[r]<=d) dfs(l,i,summ+1);
	}
}
void ma(){
	scanf("%d%d",&n,&d);
	ans=0;
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++){
		fill(sum+1,sum+n+1,0);
		fill(num+1,num+n+1,100000000000000005);
		dfs(i,i,0);
		for(int j=1;j<=n;j++)
			if(sum[j]==2) ans++;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) ma();
	return 0;
}
