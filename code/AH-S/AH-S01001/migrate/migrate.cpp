#include<bits/stdc++.h>
using namespace std;
const int N=305;
int c,t,n,f[N][N],k,sum;
long long x[N];
long long d;
void dfs(int St,int i,int j,int s) {
	if(sum>2) return;
	if(i==j) {
		if(s==f[St][j]) sum++;
		return;
	}
	for(int p=i+1;p<=n;p++) {
		if(x[i]+d>=x[p]) dfs(St,p,j,s+1);
	}
	return;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--) {
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)  scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++) {
			int p=x[i],cnt=0;
			for(int j=i+1;j<=n;j++) {
				if(p<x[j]) p+=d,cnt++;
				f[i][j]=cnt;
			}
		}
		k=0;
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				sum=0;
				dfs(i,i,j,0);
				if(sum==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

