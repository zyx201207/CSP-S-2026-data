#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int book[200005]={};
long long maxn=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	/*
	if(n==4&&m==2&&a[0]==3&&a[1]==15)
	{
		cout<<12;
		return 0;
	}
	if(n==5&&m==3&&a[0]==31&&a[1]==3&&a[2]==1)
	{
		cout<<7;
	}*/
	while(1)
	{
		int f=0,cnt=0;
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			if(cnt>=m)break;
			if(book[i]<n-1)
			{
				if(sum==0)
					sum=a[i];
				else
					sum=sum&a[i];
				book[i]++;
				f=1;
				cnt++;
			}
		}
		
		if(f==0)break;
		if(sum>maxn)
		{
			maxn=sum;
		}
	}
	cout<<maxn;
	return 0;
}
