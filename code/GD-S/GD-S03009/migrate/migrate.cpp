#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long num,ans,low,d;
long long x[2000010];
bool check(int i,int j){
	if(x[j]-x[i]<=d){
		return true;
	}else{
		return false;
	}
}
void dfs(int now,int t,long long cnt){
	if(now==t){
		if(cnt==low){
			num++;
		}
		return ;
	}
	if(cnt>low){
		return ;
	}
	int i=now+1;
	while(check(now,i)&&i<=t){
		dfs(i,t,cnt+1);
		i++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j)){
					continue;
				}
				low=(x[j]-x[i])/d;
				if((x[j]-x[i])%d!=0){
					low++;
				}
				num=0;
				dfs(i,j,0);
				if(num==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
