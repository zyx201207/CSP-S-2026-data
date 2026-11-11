#include<bits/stdc++.h>
using namespace std;
const long long N = 2e6+7;
long long c,t,n,d,arr[N],num[N],cnt[N],ans;
void dfs(long long i,long long j){
	if(cnt[i] > j){
		cnt[i] = j;
		if(num[i] == 2)	ans--;
		num[i] = 1;
	}
	else if(cnt[i] == j){
		num[i]++;
		if(num[i] == 2)	ans++;
		else if(num[i] == 3)	ans--;
	}
//	printf("dfs(%lld,%lld) cnt[i] = %lld num[i] = %lld\n",i,j,cnt[i],num[i]);
	for(long long k = i+1;k<=n;k++)
		if(arr[k] - arr[i] <= d)	dfs(k,j+1);
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans = 0;
		scanf("%lld%lld",&n,&d);
		for(long long i = 1;i<=n;i++)	scanf("%lld",&arr[i]);
		for(long long i = 1;i<=n;i++){
			for(long long j = 1;j<=n;j++){
				num[j] = 0;
				cnt[j] = N;
			}
//			memset(cnt,INF,sizeof(cnt));
			dfs(i,0);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
