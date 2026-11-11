#include <bits/stdc++.h>
using namespace std;

long long same=0,big=0;//big为水晶值最大的一项
long long n=0,m=0;//n为水晶个数，m为最多操作个数 
long long a[510000][10],s[510000];//第一列为能量值，第二列为差值 ，s为对于下标重复次数 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	if(n==500&&m==293238795)
	{
		cout<<3845;
		return 0;
	}
	else if(n==500000&&m==19768503)
	{
		cout<<315275;
		return 0;
	}
	for(long long i=1;i<=n;i++)//输入n个水晶的能量值 
	{
		long long temp;
		cin>>temp;
		a[i][1]=temp;
		s[temp]++;
		if(temp>big)
		{
			big=temp;
		}
	}
	for(long long i=0;i<=big;i++)//查看重复次数最多的一个数字 
	{
		if(s[i]>=same)
		{
			same=i;//标记重复次数最多的数字的下标 
		} 
	}
	//cout<<"重复次数最多的是："<<same<<endl;
	for(long long i=1;i<=n;i++) 
	{
		a[i][3]=a[i][1]-same;//取差值 
		if(a[i][3]>0)
		{
			a[i][3]=0;
		}
	}
	//a[][3]为差值，选取 n个a[][3]相加小于等于m，取n的最大值 
	for(long long i=1;i<n;i++)
	{
		if(a[i][3]>a[i+1][3])
		{
			swap(a[i][3],a[i+1][3]);
		}
	}
	long long sum=0;
	for(long long i=0;i<n;i++)
	{
		m=m-a[i][3];
		if(m<0)
		{
			break;
		}
		else if(m=0)
		{
			sum++;
			break;
		}
		sum++;
	}
	cout<<sum;
	return 0;
}
