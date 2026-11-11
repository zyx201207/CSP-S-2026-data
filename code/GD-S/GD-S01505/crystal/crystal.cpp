#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in",'r',stdin);
	freopen("crystal.out",'w',stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int b[n+1]={1};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//输入数据 
		b[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>i;j--)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);//比大小，排序 
			}
		}	
	}
	for(int i=1;i<=n;i++)
	{
		int s=m;
		for(int j=1;j<i;j++)
		{
			if(a[i]-a[j]<=s)
			{
				s-=(a[i]-a[j]);//得各数之间的差 
				b[i]++;
				continue;
			}
			break;
		}
	}
	int maxn=0;//定义最大当前为0 
	for(int i=1;i<=n;i++)
	{
		if(b[i]>maxn)maxn=b[i];
	}
	cout<<maxn;//输出数据 
	
}
