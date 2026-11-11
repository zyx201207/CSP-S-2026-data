#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c,t;
long long mn,ans,ts;
long long n,d,a[N];
long long sum[N];
void dfs(int x,int y,int p,int k) {
	if( p == y) {
		if(mn == 0){
			ts = k;
			mn++;
		}
		if(ts > k) {
			ts = k;
			mn = 1;
		}else if(k == ts ) {
			mn++;
		}
	}
	for(int i = p + 1 ;i <= y;i++) {
		if(sum[i] - sum[p] <= d) {
			dfs(x,y,i,k+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		ans = 0;
		scanf("%lld%lld",&n,&d);
		scanf("%lld",&a[1]);
		sum[1] = 0;
		for(int i = 2 ;i <= n ;i++)  {
			scanf("%lld",&a[i]);
			sum[i] = sum[i-1] + a[i] - a[i-1]; 
		}
		for(int i = 1 ;i <= n - 2 ;++i) {
			for(int j = i+2;j<=n;++j) {
				mn = 0;
				 
				dfs(i,j,i,0); 
				if(mn == 2) {
					ans++; 
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
