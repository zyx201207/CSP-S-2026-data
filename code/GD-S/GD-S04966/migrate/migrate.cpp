#include <bits/stdc++.h>
using namespace std;
int c,t,n,ans,mi,m,o,l;
long long d,x[2000010];
void dfs(int a,int b,int z){
	if(a==b&&z==mi){
		l++;
		return;
	}
	if(a==b||z==mi)
		return;
	for(int i=a;i<b;i++){
		if(x[a]+d<x[i])
			break;
		dfs(i+1,b,z+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				m=i,o=0,mi=1,l=0;
				for(int k=i;k<=j;k++){
					if((x[m]+d<x[k]&&k==i)){
						o=1;
						break;
					}
					if(x[m]+d<x[k])
						mi++,m=k-1;
					if(k==j)
						mi++,m=k;
				}
				if(o)
					break;
				dfs(i,j,1);
				if(l==2)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
