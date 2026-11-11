#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200007];
long long ans=0;
void dfs(int st,long long num,int ci){
	if(st>n){
		if(ci==m){
			ans=max(ans,num);
		}
		return ;
	}
	if(m-ci>n-st+1) return ;
	if(ci==m) {
		ans=max(ans,num);
		return ;		
	}
	dfs(st+1,num,ci);
	if(num==0){
		dfs(st+1,a[st],ci+1);
	} 
	else dfs(st+1,num&a[st],ci+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
} 
