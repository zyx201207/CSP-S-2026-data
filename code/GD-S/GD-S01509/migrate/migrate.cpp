#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+10;
int test_id,T,n,d,a[N],dis[N][N],ans;
void init(){
	for(int i = 1;i<=n;i++)
		for(int j = i+1;j<=n&&a[j]-a[i]<=d;j++)
			dis[i][j] = 1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&test_id,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i<=n;i++)
			scanf("%lld",&a[i]);
		init();
		for(int l = 3;l<=n;l++)
			for(int i = 1;i<=n-l+1;i++){
				int j = i+l-1;
				if(a[j]-a[i]<=d) continue;
				for(int k = i+1;k<j;k++)
					dis[i][j]+=dis[i][k]*dis[k][j];
				if(dis[i][j]==2)
					ans++;
			}
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
