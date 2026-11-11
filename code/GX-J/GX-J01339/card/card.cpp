#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector <long long> a(n),ans(m+1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		vector <bool> b(m+1,0);
		vector <long long> c(n-i);
		for(int j=i;j<n;j++)
		{
			c[j-i]=a[j];
			if(b[a[j]]==1)
			{
				for(int o=0;o<n-i;o++)
				{
					if(c[o]==a[j])
					{
						for(int k=o;k<j-i;k++)
						{
							b[c[k]]=0;
							c[k]=0;
						}
						break;
					}
				}
			}
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]==1)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i==m)
		{
			cout<<ans[i];
			break;
		}
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
