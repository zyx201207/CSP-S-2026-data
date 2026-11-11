#include<bits/stdc++.h>
using namespace std;
int n,m,k=1,cnt;
int a[500005];
int c[300005];
int t[300003];
int w[300003];	
int l[500005];
int r[500005];
int main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int z=1;z<=n;z++)
	{
		for(int i=1;i<=n;i++)
		{
			t[i]=0;
			w[i]=0;
			l[i]=0;
			r[i]=0;
		}
		k=1;
		cnt=0;
		for(int i=z;i<=n;i++)
		{
			if(t[a[i]]==0)
			{
				w[a[i]]=i;
			}
			t[a[i]]++;
			if(t[a[i]]>=2)
			{
				cnt++;
				l[cnt]=w[a[i]];
				r[cnt]=i-1;
				w[a[i]]=i;
				for(int i=l[cnt];i<=r[cnt];i++)
				{
					t[i]--;
				}
			}
		}
		for(int i=z;i<=n;i++)
		{
			if(i==r[k]+1)
			{
				k++;
			}
			if(i>=l[k]&&i<=r[k])
			{
				
			}
			else
			{
				c[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	
	return 0;
}
