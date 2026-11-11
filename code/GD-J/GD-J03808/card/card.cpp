#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<long long>a(n+1,0);
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	vector<long long>b(m+5,0);
	vector<long long>c(m+5,0);
	for(long long i=1;i<=n;++i)
	{
		for(long long j=i;j<=n;++j)
		{
			if(!b[a[j]])
			{
				b[a[j]]=j;
			}
			else
			{
				for(long long k=1;k<=m;++k)
				{
					if(b[k]>b[a[j]]&&b[k]<j)
					{
						b[k]=0;
					}
				}
				b[a[j]]=j;
			}
		}
		for(long long k=1;k<=m;++k)
		{
			if(b[k])
			{
				c[k]++;
			}
			b[k]=0;
		}
	}
	for(long long i=1;i<=m;++i)
	{
		cout<<c[i]<<" ";
	}
}
