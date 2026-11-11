#include<bits/stdc++.h>
using namespace std;
int s[500005];
int r[500005];
int tj[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	bool p;
	for(int js=0;js<n;js++)
	{
		for(int i=0;i<n;i++)
		{
			r[i]=0;
		}
		for(int i=js;i<n;i++)
		{
			p=true;
			for(int j=i-1;j>=0;j--)
			{
				if(s[i]==r[j])
				{
					p=false;
					for(int ij=j;ij<i;ij++)
					{
						r[ij]=0;
					}
				}
				if(!p)
				{
					break;
				}
			}
				r[i]=s[i];
		}
		for(int i=0;i<n;i++)
		{
			if(r[i]!=0)
			{
				tj[r[i]]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<tj[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
