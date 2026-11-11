#include <bits/stdc++.h>
using namespace std;
int d[200010],ans,n,m;
int dfs(int t,int a,int step){
	if(t>m||step>=n-1) return a;
	ans=max(dfs(t+1,(a&d[step-1]),step+1),dfs(t,a,step+1));
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&d[i]);
	printf("%d\n",dfs(0,d[0],1));
	return 0;
}
