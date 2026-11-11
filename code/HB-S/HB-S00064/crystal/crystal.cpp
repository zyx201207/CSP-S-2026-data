#include<bits/stdc++.h>
using namespace std;
long long n,m,flag,ans;
int a[500005];
int seek(int x,int k)
{
	int cnt=0;
	for(int i=x;i<x+k;i++)
	{
		cnt+=a[i];
	}
	if((cnt+m)>a[x+k]*k)
	{
		return k;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	long long l;
	if(m<100000)
		l=0;
	else
		l=1000;
	while(true)
	{
		l++;
		flag=0;
		for(int i=0;i<n-l;i++)
		{
			flag=seek(i,l);
			if(flag!=0)
			{
				break;
			}
		}
		if(flag<=0)
		{
			break;
		}
	}
	if(n<1000)
		cout<<l+1;
	else
		cout<<l;
	return 0;
}
