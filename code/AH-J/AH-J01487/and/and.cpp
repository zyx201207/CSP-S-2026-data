#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxx,minn=INT_MAX,wn2[31],ans;
bool wn[31][200001];
int fpow(int x)
{
	if(x==0)
	{
		return 1;
	}
	if(x==1)
	{
		return 2;
	}
	else if(x%2==0)
	{
		return fpow(x/2)*fpow(x/2);
	}
	else
	{
		return fpow(x-1)*2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>maxx)
		{
			maxx=a[i];
		}
		if(a[i]<minn)
		{
			minn=a[i];
		}
		int w=0;
		while(a[i]>0)
		{
			wn[w][i]=a[i]%2;
			wn2[w++]+=a[i]%2;
			a[i]/=2;
		}
	}
	if(m==1)
	{
		cout<<maxx;
	}
	else if(m==n)
	{
		for(int i=30;i>=0;i--)
		{
			if(wn2[i]>=m)
			{
				ans+=fpow(i);
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=30;i>=0;i--)
		{
			if(wn2[i]>m)
			{
				ans+=fpow(i);
				for(int j=0;j<n;j++)
				{
					if(wn[i][j]==0)
					{
						for(int k=0;k<m;k++)
						{
							if(wn[k][j]==1)
							{
								wn2[k]--;
							}
						}
					}
				}
			}
			if(wn2[i]==m)
			{
				ans+=fpow(i);
			}
		}
		cout<<ans;
	}
	return 0;
}
