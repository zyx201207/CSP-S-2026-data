#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],ans;
long long maxx(long long a,long long b){
	if(a>b)return a;
	return b;
}void dfs(int cnt,int pos,long long x){
	if(cnt==m){
		ans=maxx(ans,x);
		return; 
	}for(int i=pos+1;i<=n;i++)dfs(cnt+1,i,x & a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)dfs(1,i,a[i]);
	printf("%d",ans);
	return 0;
}
