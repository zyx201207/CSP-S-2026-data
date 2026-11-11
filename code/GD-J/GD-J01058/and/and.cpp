#include<iostream>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int dfs(int u,int s){	
	if(s==0) return 2147483647;
	if(u>n) return 0;
	int t=max(dfs(u+1,s),dfs(u+1,s-1)&a[u]);
	return t;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}
	printf("%d",dfs(1,m));
	return 0;
}
