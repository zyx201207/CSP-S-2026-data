#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
long long a[114514];
bool f[114451];
long long dp[114514];
void dfs(long long step,long long num){
	if(step==m+1){
		ans=max(ans,num);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(step==1){
				dfs(step+1,a[i]);	
			}else{
				dfs(step+1,a[i]&num);
			}
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
