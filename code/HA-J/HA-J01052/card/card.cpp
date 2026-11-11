#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],c[300005],num;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		num=0;
		for(int j=i;j<=n;j++)
		{
			num++;
			s[num]=a[j];
			for(int k=1;k<num;k++)
			{
				if(s[k]==s[num])
				{
					for(int l=k;l<=num;l++)
					{
						s[l]=0;
					}
					s[k]=a[j];
					num=k;
					break;
				}
			}
		}
//		cout<<"n"<<num<<" ";
		for(int j=1;j<=num;j++)
		{
			if(s[j]!=0)
			{
				c[s[j]]++;
//				cout<<s[j]<<"p ";
			}
		}
		memset(s,0,sizeof(s));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
