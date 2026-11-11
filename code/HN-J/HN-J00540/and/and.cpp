#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans=-1;
int nums[200010];
bool mark[200];

void dfs(int cnt,int now){
	if(cnt==m){
		ans=max(ans,now);
		return;
	}
	if(now<=ans) return ;
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			mark[i]=1;
			dfs(++cnt,now&nums[i]);
			mark[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",nums[i]);
	}
	if(n<=20){
		dfs(0,2097151);
		printf("%d",ans);
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(nums[i],ans);
		}
		printf("%d",ans);
		return 0;
	}
	if(m==n){
		ans=nums[1];
		for(int i=1;i<=n;i++){
			ans&=nums[i];
		}
		printf("%d",ans);
		return 0;
	}
	if(m==n-1){
		int temp_ans=2147483647;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					temp_ans&=nums[j];
				}
			}
			ans=max(temp_ans,ans);
		}
		printf("%d",ans);
		return 0;
	}
	if(m==2){
		int temp_ans=2147483647;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				temp_ans=nums[i]&nums[j];
			}
			ans=max(temp_ans,ans);
		}
		printf("%d",ans);
		return 0;
	}
	else{
		sort(nums+1,nums+1+n);
		printf("%d",nums[n-m+1]);
	}
	return 0;
}

