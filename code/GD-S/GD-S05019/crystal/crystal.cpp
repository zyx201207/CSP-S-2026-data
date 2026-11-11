#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ull unsigned long long 
using namespace std;
int n,a[500050],mid,sum=1,l,r;
//sum为最终结果 mid为整个数列的中间值
//temp为他们与中值的差 
//temp1为向左一格 temp2为向右一格 
ull m;
int cxy(int a)
{
	if(a>=0) return a;
	else return -a;
}
void kskbl(int n)
{
	if(n==1)
	{
		cout<<1<<endl;
		return ;
	}
	if(n==2)
	{
		if(a[1]+m>=a[2])
		{
			cout<<2<<endl;
			return;
		}
		else
		{
			cout<<1<<endl;
			return;
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=5)
	{
		sort(a+1,a+n+1);
	if(n<=2)
	{
		kskbl(n);
		return 0;
	}
	if(n%2==1)
		mid=n/2+1;
	else mid=n/2;	
	for(int i=m,l=mid-1,r=mid+1;i>=0;)
	{
		int temp1=cxy(a[mid]-a[l]);
		int temp2=cxy(a[mid]-a[r]);
		if(l!=0&&r!=n+1)
		{
		if(temp1<=temp2)
		{
			if(temp1<=i)
			{
				i-=temp1;
				sum++;
				if(l-1>=0) l--;
			}
			else
			{
				cout<<sum<<endl;
				return 0;
			}
		}
		else
		{
			if(temp2<=i)
			{
				i-=temp2;
				sum++;
				if(r+1<=n+1) r++;
			}
			else
			{
				cout<<sum<<endl;
				return 0;
			}
		}
	}
	else
	{
		if(l==0&&r!=n+1)
		{
			if(temp2<=i)
			{
				i-=temp2;
				sum++;
				if(r+1<=n) r++;
			}
			else
			{
				cout<<sum<<endl;
				return 0;
			}
		}
		else if(l!=0&&r==n+1)
		{
			if(temp1<=i)
			{
				i-=temp1;
				sum++;
				if(l-1>=1) l--;
			}
			else
			{
				cout<<sum<<endl;
				return 0;
			}
		}
		else if(l==0&&r==n+1)
		{
			cout<<sum<<endl;
			return 0;
		}
	}
	}
	}
	if(n>5)
	{
		int temp=a[2]-a[1];
		for(int i=2;i<=n;i++)
		{
			if(m<(a[i]-a[1]+temp)*(i-1)/2)
			{
				cout<<i-1<<endl;
				return 0;
			}
		}
	}
	return 0;
}

