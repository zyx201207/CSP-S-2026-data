#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;	
} 
bool check(int x)
{
	for(int i=0;i<=20;i++)
	{
		if(pow(2,i)==x)return true;
	}
	return false;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0,flag=0,flag2=0,kkk=1;
	cin>>n>>m;
	int a[n+5]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(m==1)
	{
		cout<<a[1];
		kkk=0;
	}
	if(m==2&&kkk)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		kkk=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i-1)flag=1;
	}
	if(!flag&&kkk)
	{
		cout<<n-m;
		kkk=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!check(a[i]))flag2=1;
	}
	if(!flag2&&kkk)
	{
		cout<<a[n-m];
		kkk=0;
	}
	
	return 0;
} 
