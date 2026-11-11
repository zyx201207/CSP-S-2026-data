#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005],b[300005],t;
bool x[300005];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		memset(b,0,sizeof(b));
		memset(x,false,sizeof(x));
		for(int j=i;j<=n;j++)
		{
			t++;
			b[t]=a[j];
			if(x[a[j]])
			{
				bool f=false;
				int r=t;
				for(int k=1;k<=r;k++)
				{
					if(f)
					{
						x[b[k]]=false;
						b[k]=0;
					}
					else if(a[k]==a[j])
					{
						f=true;
						t=k;
					}
				}
				x[a[j]]=true;
			}
			else
			{
				x[a[j]]=true;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(x[j])
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
