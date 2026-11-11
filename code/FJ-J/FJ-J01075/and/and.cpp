#include<bits/stdc++.h>//a&b
using namespace std;
int n,m,a[200005],ans,sam[200005],tmpamax;
void dfs(int nw,int x,int i)
{
	if(i>n+1)return;
	if(nw>m)return;
	if(nw==m)
	{
		ans=max(ans,x);return;
	}
	dfs(nw,x,i+1);
	dfs(nw+1,x&a[i],i+1);
	return ;
}
bool sec(int x,int y)
{
	int tmp=1073741824;
	while(tmp>0)
	{
		if(x<tmp and y>=tmp)return 0;
		if(x>=tmp)x-=tmp;
		if(y>=tmp)y-=tmp;
		tmp/=2;
	}
	return 1;
}
bool check(int x)
{
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		if(sec(a[i],x))tmp++;
		//printf("%d ",x);
	}
	//printf("\n");
	if(tmp>=m)return 1;
	else return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	sam[0]=2147483647;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sam[i]=sam[i-1]&a[i];
		tmpamax=max(tmpamax,a[i]);
	}
	//printf("%d",s);
	if(m==1){
		printf("%d",tmpamax);
		return 0;
	}
	if(m==n)
	{
		printf("%d",sam[n]);
		return 0;
	}
	int l=0,r=1073741824,mid=0;
	while(l!=r-1)
	{
		mid=l+(r-l)/2;
		if(check(mid))l=mid;
		else r=mid;
		//printf("%d %d\n",l,r);
	}
	//dfs(0,2147483647,1);
	printf("%d",l+(r-l)/2);
	return 0;
}
