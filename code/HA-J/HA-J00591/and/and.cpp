#include<iostream>
#include<cstdio>
using namespace std;
int a[300000],b[300000],l=1,n,m;
void dfs(int k,int ans,int cnt){
	if(cnt>m){
		b[l++]=ans;
		return;
	}
	for(int i=k;i<=n;i++){
		if(k==1)dfs(i+1,a[i],cnt+1);
		else dfs(i+1,ans&a[i],cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,1);
	int maxn=-1;
	for(int i=1;i<l;i++){
		if(b[i]>maxn)maxn=b[i];
	}
	cout<<maxn;
	return 0;
}
