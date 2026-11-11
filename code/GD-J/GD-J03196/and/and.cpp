#include<bits/stdc++.h>
using namespace std;
int a[2000001],n,m;
int ans;
bool cnd(int a,int b){
	return a>b;
}
void dfs(int now,int sum,int maxx){
	if(maxx==m+1){
		ans=max(sum,ans);
		
		return;
	}
	if(now>n||sum==0)return;
	dfs(now+1,sum&a[now],maxx+1);
	dfs(now+1,sum,maxx);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cnd);
	
	dfs(1,a[1],1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;	
}
//coder by:chen
