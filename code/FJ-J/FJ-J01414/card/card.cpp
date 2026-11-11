#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000001],b[5000001],f[5000001],c[5000001],d[5000001],e[5000001],maxx;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=a[i];
		maxx=max(a[i],maxx);
	}
	int t1=0,t=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		t1=0;
		for(int j=1;j<=n;j++)
			b[j]=0,e[j]=0,c[j]=0;
		for(int h=i;h<=n;h++)
		{
			if(b[f[h]]!=1)
			{
				for(int j=1;j<=t1;j++)
				{
					if(f[h]==c[j])
					{
						for(int k=j;k<=t1;k++)
							b[f[k]]=1;
						t1=j;
						t=1;
						break;
					}
				}
				if(t==0)
					t1++;
				c[t1]=f[h];
			}
			t=0;
		}
		for(int j=1;j<=t1;j++)
		{
			if(e[c[j]]==0)
				d[c[j]]++,e[c[j]]++;
		}
	}
	for(int i=1;i<=maxx;i++)
		cout<<d[i]<<" ";
	return 0;
}
