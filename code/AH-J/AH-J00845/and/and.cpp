#include <bits/stdc++.h>
using namespace std;
int a[200005],ma=-1,n,m,fff[200005];
void dfs(int sf,int st=0,int st2=0){
	if(st2==m){
		ma=max(ma,sf);
		return;
	}
	if(fff[st]>=sf)return;
	fff[st]=sf;
	if(st>0)for(int i=st;i<n&&n-i>=m-st2;++i){
		dfs(a[i]&sf,i+1,st2+1);
		if(a[i]==sf)return;
	}
	else for(int i=st;i<n&&n-i>=m-st2;++i)dfs(a[i],i+1,st2+1);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int f;
	cin>>n>>m;
	for(int i=0;i<n;++i)scanf("%d",&a[i]); 
	sort(a,a+n,cmp);
	if(m>=16384){
		f=a[0];
		for(int i=1;i<m;++i)f&=a[i];
		cout<<f;
		return 0;
	}
	memset(fff,-1,sizeof fff);
	dfs(0);
	cout<<ma;
	return 0;
}
