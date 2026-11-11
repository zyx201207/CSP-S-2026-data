#include"bits/stdc++.h"
using namespace std;
int m,n;
int a[1000005];
int mx=-1;
void dfs(int x,int y,int z){
	if(y==m){
		mx=max(mx,z);
		return;
	}
	if(x==n+1)
		return;
	dfs(x+1,y+1,z&a[x]);
	dfs(x+1,y,z);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int tmp=a[1];
	for(int i=2;i<=n;i++)
		tmp&=a[i];
	if(m==n){
		printf("%d\n",tmp);
		return 0;
	}
	if(m==1){
		int tmp=-1;
		for(int i=1;i<=n;i++)
			tmp=max(tmp,a[i]);
		printf("%d\n",tmp);
		return 0;
	}
	if(m==2){
		int tmp=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				tmp=max(tmp,a[i]&a[j]);
		printf("%d\n",tmp);
		return 0;
	}
	dfs(1,0,-1);
	printf("%d\n",mx);
	return 0;
}
