#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,cnt=0;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		b[i]=a[i];
		for(int j=0;j<i;j++)
		{
			if(a[i]==b[j])
			{
				for(int s=j;s<i;s++)
				{
					b[s]=0;
				}
			}
		}
		if(b[i]==n)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
