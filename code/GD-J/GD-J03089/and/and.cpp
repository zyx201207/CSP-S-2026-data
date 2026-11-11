#include<bits/stdc++.h>
using namespace std;
int n,m,a[200003],b[200003],maxx=-1;
void dfs(int k,int beans,int l){
	if(l==m+1)return;
	for(int i=k;i<=n;i++)
	{
		if(l==1)beans=a[i];
		b[l]=a[i];
		int h=b[l]&beans;
		dfs(i+1,h,l+1);
		if(h>maxx&&l==m)
		{
			maxx=h;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	memset(b,0,sizeof(b));
	dfs(1,1,1);
	printf("%d",maxx);
	return 0;
}
