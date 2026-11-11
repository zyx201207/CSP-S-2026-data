#include <bits/stdc++.h>
using namespace std;
int n,r,maxn,a[200005];
int fx(int x,int y)
{
	int a[10005],b[10005],len_1=0,len_2=0;
	string ans="";
	for(int i=0;i<10000;i++)
		a[i]=0,b[i]=0;
	while(x!=0)
	{
		a[len_1++]=x%2;
		x/=2;
	}
	while(y!=0)
	{
		b[len_2++]=y%2;
		y/=2;
	}
	int t=1;
	for(int i=max(len_1,len_2)-1;i>=0;i--)
	{
		ans[i]=a[i] and b[i];
		t=t*10+ans[i];
	}
	return t;
}
void dfs(int num,int cnt)
{
	if(num==r)
	{
		maxn=max(maxn,cnt);
		return;
	}
	for(int i=num+1;i<=n;i++)
	{
		dfs(num+1,fx(cnt,a[i]));
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>r;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0,1);
	//cout<<fx(31,fx(15,7))<<endl;
	cout<<maxn;
	return 0;
}
