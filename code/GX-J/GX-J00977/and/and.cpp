#include<bits/stdc++.h>
using namespace std;
int a[100010],n,m,v[100010],ans;
void check(){
	int c=-1;
	for(int i=1;i<=n;i++){if(v[i]==1){if(c==-1){c=a[i];}c&=a[i];}}
	ans=max(ans,c);
}
void dfs(int k,int cnt){
	if(k>n){if(m!=cnt)return;check();return;}
	v[k]=1;dfs(k+1,cnt+1);v[k]=0;dfs(k+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);cout<<ans;return 0;
}
