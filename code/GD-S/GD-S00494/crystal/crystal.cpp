#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,m,sum=1;
	cin>>a>>m;
	int z[a];
	for(int i=1;i<=a;i++)
	{
		cin>>z[i];
	}
	for(int i=1;i<=a;i++)
	{
		if(z[i]==z[i+1])
		{
			sum++;
		}
		if(z[i]<z[i+1]&&m>0)
		{
			if(m-(z[i+1]-z[i])>=0)
			{
				m=m-(z[i+1]-z[i])*i;
				z[i]=z[i+1];
				sum++;
			}
		}
		cout<<m<<" ";
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
