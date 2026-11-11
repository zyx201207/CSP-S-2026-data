#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],n1,m1;
long long b[1000010],c[1000010],d[1000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
			d[a[i]]=b[a[i]];
		}
	for(int i=1;i<=n;i++)
		{
			b[a[i-1]]--;
			d[1000010]=b[1000010];
			for(int j=n;j>=i;j--)
			{	
				if(n1>1)
				{
					if(a[j]==m1)
						{
							n1--;
							d[a[j]]--;
							continue;
						}
					else d[a[j]]--;
				}
				if(n1==1) 
					n1=0;
				if(d[a[j]]==1&&n1==0)
					c[a[j]]++;
				if(d[a[j]]>1&&n1==0&&m1!=d[a[j]])
				{
					n1=d[a[j]];
					m1=a[j];
					c[a[j]]++;
				}
			}
			n1=0;
			m1=0;
		}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
return 0;
}
