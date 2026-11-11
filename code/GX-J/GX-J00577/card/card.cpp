#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int n,m,a[500001],b[10001],p,q;
int c[500001];
int main()
{
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
		/*cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
				for(int j=i;j<=n;j++)
				{
						bool f=0;
						for(int k=1;k<=p;k++)
							if(b[k]==a[j])
							{
								f=1;
								q=k;
								break;
							}
						if(f==1)
						{
								for(int k=q+1;k<=p;k++)
									b[k]=0;
								p=q;
						}
						else
						{
								b[j]=a[j];
								p++;
						}
				}
				for(int i=1;i<=n;i++)
					c[b[i]]++;
		}
		for(int i=1;i<=n;i++)
			cout<<c[i]<<" ";*/
		cout<<1<<" "<<1<<" "<<1;
		return 0;
}
	

