#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[500005],b[300005],l[300005];//a是记录牌的顺序，b是记录出现总次数，l是记录最后一次出现的位置 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		l[a[i]]=i;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;)
		{
		    if(l[a[j]]==j)
			{
				b[a[j]]++;
				j++;
			}
			else j=l[a[j]];
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
