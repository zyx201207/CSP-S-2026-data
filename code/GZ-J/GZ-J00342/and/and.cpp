//遵义汇川区周林 陈俊洁 GZ-J00342
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
int vis[200005];
int p[200005];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int cnt,int now){
	if(cnt==m){
		int ans_now=p[1];
		for(int i=2;i<=cnt;i++){
//			cout<<p[i]<<"+++++\n";
			ans_now=(ans_now&p[i]);
		}
		ans=max(ans,ans_now);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		p[i]=a[i];
//		cout<<p[i]<<"+++\n";
		dfs(cnt+1,p[i]);
		p[i]=0;
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dfs(0,0);
	cout<<ans;
	return 0;
}

