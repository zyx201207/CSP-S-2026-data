#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[3005],c[2],d[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(m==1) cout<<n;
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			c[a[i]]++;
			if(a[i]==1)
			{
				if(a[n]==2) c[a[n]]++;
			}
			else
			{
				if(a[n]==1) c[a[n]]++;
			}
		}
		cout<<c[1]<<" "<<c[2];
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				b[a[j]]=1;
				int f=0;
				for(int k=j-1;k>=i;k--)
				{
					if(a[k]==a[j])
					{
						f=1;
						break;
					}
				}
				if(f==1)
				{
					for(int k=j-1;k>=i;k--)
					{
						if(a[k]==a[j]) break;
						b[a[k]]=0;
					}
				}	
			}
			for(int j=1;j<=m;j++)
			{
				d[j]+=b[j];
				b[j]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			printf("%lld ",d[i]);
		}
	}
	return 0;
}
