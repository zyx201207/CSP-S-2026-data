#include<bits/stdc++.h>
using namespace std;
int const MAXN=(int)2e6+5;
long long a[MAXN];
int n;
long long m;
long long d[MAXN];
long long ans;
void F(int kk){
	memset(d,0,sizeof(d));
	d[kk]=1;
	for(int i=kk;i<=n;i++){
		int j=i+1;
		while(j<=n && a[j]-a[i]<=m){
			j++;
		}
		if(j==i+1){
			continue;
		}
		d[j-1]+=d[kk];
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			F(i);
			if(d[n]==2){
				ans++;
			}
			
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
