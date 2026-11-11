#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int a[MAXN],n,m,ans=-1;
void DFS(int x,int y,int anss){
	if(y==m){
		ans=max(ans,anss);
		return;
	}
	if(n-x+y<m)return;
	if(y<m&&anss>ans){
		if(y>0)DFS(x+1,y+1,anss&a[x]);
		else DFS(x+1,1,a[x]);
	}
	DFS(x+1,y,anss);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1){
		for(int i=1;i=n;i++)ans=max(ans,a[i]);
		printf("%d",ans);
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		printf("%d",ans);
	}else{
		DFS(1,0,0);
		printf("%d",ans);
	}
	return 0;
}
