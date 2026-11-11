#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,a[200010];
int anweiyu(int x,int y){
	int b[40]={0},c[40]={0},d[40]={0},bb=0,cc=0;
	while(x>0){
		if(x%2==0)b[++bb]=0;
		else b[++bb]=1;
		x/=2;
	}
	while(y>0){
		if(y%2==0)c[++cc]=0;
		else c[++cc]=1;
		y/=2;
	}
	for(int i=1;i<=max(cc,bb);i++){
		if(b[i]==1&&c[i]==1)d[i]=1;
		else d[i]=0;
	}
	int z=0;
	for(int i=max(bb,cc);i>=1;i--){
		z*=2;
		z+=d[i];
	}
	return z;
}
void dfs(int wei,int zhi,int sum){
	if(sum==m){
		maxn=max(anweiyu(a[wei],zhi),maxn);
		return;
	}
	int maxm,maxid;
	for(int i=wei+1;i<=n;i++){
		if(maxm<anweiyu(a[i],zhi)){
			maxm=anweiyu(a[i],zhi);
			maxid=i;
		}
	}
	dfs(maxid,maxm,sum+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-m+1;i++){
		dfs(i,a[i],1);
	}
	cout<<maxn<<'\n';
	return 0;
}
//4 2
//3 15 12 12
