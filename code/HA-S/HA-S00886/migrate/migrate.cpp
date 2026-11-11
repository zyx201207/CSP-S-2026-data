#inclde<bits/stdc++.h>
using namespace std;
int a[100000]
int main()
{
	freopen("migrate.in""r"stdin);
	freopen("migrate.out""w"stdout);
	int c,t,h1=0,h2=0;
	cin>>c>>t;
	for(int z=1;z<=t;z++)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cim>>a[i];
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]-a[j]<=d)
				{
					h1+=1;
				}
			}
		}
		for(int i=n;i>=1;i-d)
		{
			h2+=1;
		}
		if(h1==h2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}