#include<bits/stdc++.h>
using namespace std;
int m,n,l,a[200100];
bool cmp(int x,int y){
	return x>y;
}
int ans;
void dfs(int k,int j,int cnt){
	if(k>m){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=j-1;i>=1;i--){
		if(log2(a[n-m+1])+1<l) break;
		dfs(k+1,i,cnt&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	l=log2(a[n-m+1])+1;
	dfs(1,n+1,pow(2,31)-1);
	printf("%d",ans);
	return 0;
}

