#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5005];
long long tong[3005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		long long aaa[50005];
		memset(aaa,0,sizeof(aaa));
		for(int j=i;j<=n;j++)
		{
			aaa[j]=a[j];
			bool bbb=true;
			long long ccc=0;
			for(int q=1;q<j;q++)
			{
				if(aaa[j]==aaa[q])
				{
					bbb=false;
					ccc=q;
					continue;
				}
			}
			if(bbb==false)
			{
				for(int q=ccc;q<j;q++)
				{
					aaa[q]=0;
				}
			}
		}
		long long tongtong[3005];
		memset(tongtong,0,sizeof(tongtong));
		for(int j=i;j<=n;j++)
		{
			if(aaa[j]!=0)tongtong[aaa[j]]++;
		}
		for(int j=1;j<=3005;j++)
		{
			if(tongtong[j]!=0)
			{
				tong[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<' ';
	}
	return 0;
}

