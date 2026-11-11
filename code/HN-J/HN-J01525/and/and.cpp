#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m,maxx;
int cnt=1;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int u,int x,int num){
	if(u>m){
		maxx=max(num,maxx);
		return;
	}
	for(int i=x;i<=n;i++){
		dfs(u+1,i+1,num&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i <= n;i++) dfs(2,i+1,a[i]);
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
