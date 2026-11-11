#include<iostream>
#include<algorithm>
using namespace std;
long long lst[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>lst[i];
	}
	long long max=0;
	if(m==1)
	{
		for(long long i=0;i<n;i++)
		{
			if(lst[i]>m)
			{
			max=lst[i];}
		}
	}
	else if(n<=20)
	{
		long long mi=0,mj=0;
		for(long long i=0;i<n;i++)
		{
			for(long long j=i+1;j<n;j++)
			{
				if(lst[i]&lst[j]>max)
				{
					max=lst[i]&lst[j];
					mi=i;mj=j;
				}
			}
		}
		lst[mi]=0;
		lst[mj]=0;
		m-=2;
		while(m>0){
			long long max2=0;
			for(long long j=0;j<n;j++)
			{
				if(lst[j]&max>max2)
				{
					max2=lst[j]&max;
					mj=j;
				}
			}
			lst[mj]=0;
			max=max2;
			m--;
		}
	}
	else
	{
		sort(lst,lst+n);
		cout<<lst[n-m];
	}
	cout<<max;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
