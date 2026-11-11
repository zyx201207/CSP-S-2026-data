#include<bits/stdc++.h>
using namespace std;
long long a[200005],m,n,ans;
void slove(long long point,long long cnt,long long num)
{
	if(m-cnt-1>n-point)
	{
		return;
	}
	if(cnt==m)
	{
		ans=max(num,ans);
		//cout<<'|';
		return;
	}
	long long new_num;
	if(num==-1)
	{
		new_num=a[point];
	}
	else
	{
		new_num=num&a[point];
	}
//	cout<<a[point]<<',';
	
	for(int i=1;i<=n-point+1;i++)
	{
		slove(point+i,cnt+1,new_num);
	}
	slove(point+1,cnt,num);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	slove(1,0,-1);
	cout<<ans;
}
