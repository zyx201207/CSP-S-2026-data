//GZ-J00040 贵阳市第二实验中学 岑钰欣 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n],d[m+1]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	for(int k=0;k<n;k++)
{
	int b[m+1]={0},d[n],c=0;
	for(int i=k;i<n;i++)
	{
		if(b[a[i]]==1)
		{
			for(int j=c;j<i;j++)b[a[j]]=0;
			c=i;
		} 
		b[a[i]]++;
	}
	for(int i=k;i<n;i++)d[a[i]]+=b[a[i]];
}
	for(int i=1;i<=m;i++)
	{
		cout<<d[a[i]]<<" ";
	}
	return 0;
}
