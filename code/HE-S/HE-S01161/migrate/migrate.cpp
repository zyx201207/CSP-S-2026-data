#include<bits/stdc++.h>
using namespace std;
long long int c,t,n[200005],d[200005],x[200005],a,lx,zs[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>x[j];
			if(x[1]-x[j]<=d[i])
			{
				x[1]=x[j];
				a=x[j];
				if(a>=x[t])
				{
					lx++;
				}
				if(lx==2)
				{
					zs[i]=zs[i]+1;
				}
			}
		}
	}
	for(int i=1;i<=t;i++)
	 //for(int i=0;i<=n[i];i++)
	 {
	 	cout<<zs[i]<<endl;
	 }
	 return 0;
}
