#include<bits/stdc++.h>
using namespace std;
long long n,m,kmax=0,flag=0,o;
 
int a[500010];
int qian[500010];
int main()
{
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	o=m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]; 
		if(a[i]==i)
		{
			flag++; 
		}
	}
	if(flag==n)//特殊性质A特判 
	{
		if(m==1)
		{
			cout<<2;
			return 0;
		} 
		for(long long i=2;i<=n;i++)
		{
			if(o-i>0) o=o-i;
			else
			{
				cout<<i;
				return 0;
			}
		}		
		
	}
	sort(a+1,a+n+1);//坑！！！ 
	for(long long i=1;i<=n;i++)
	{
		qian[i]=qian[i-1]+a[i];//前缀和数组 
	}
	/*	for(int i=1;i<=n;i++)
	{
		cout<<qian[i]<<" ";
	}*/
	for(long long l=1;l<=n;l++)
	{
		for(long long r=l;r<=n;r++)
		{
			if((r-l+1)*a[r]<=m+qian[r]-qian[l-1])
			{
				kmax=max(r-l+1,kmax);
			}
		}
	}
	
	cout<<kmax;
	return 0;
}
//能过前9个n小于5000的点 45分或者60分左右吧 A不知道数据会不会太大B特殊点没看懂 


