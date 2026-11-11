#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
int a[200050];

void dfs(int k,int m,int sum){
	if(m>M){
		ans=max(sum,ans);
		return ;
	}
	if(k>N){
		return;
	}
	if(sum<ans){
		return ;
	}
	dfs(k+1,m+1,(sum&a[k]));
	dfs(k+1,m,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+N+1,[](int x,int y){
		return x>y;	
	});
	dfs(1,1,1073741823);
	printf("%d",ans);
	return 0;
}
