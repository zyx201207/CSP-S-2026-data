#include<iostream>
#include<cstdio>

using namespace std;

int num[200005];
int p[200005];
int ans;
int n,k;

void dfs(int i,int x,int sum){
	if(x==k){
		ans=max(ans,sum);
		return ;
	}
	if(n-i+x<k) return ;
	i++;
	for(;i<=n;i++){
		p[x+1]=num[i];
		dfs(i,x+1,sum&num[i]);
	}
	p[x+1]=0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	dfs(0,0,(1<<30)-1);
	printf("%d",ans);
}