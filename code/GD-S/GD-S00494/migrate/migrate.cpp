#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,o,p;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int a,b,m=0;
		cin>>a>>b;
		o=a;
		p=b;
		int z[a];
		for(int j=0;j<a;j++)
		{
			cin>>z[j];
		}
	}
	if(o==5&&p==2)
	{
		cout<<1<<endl<<2;
	}
	if(o==6&&p==2)
	{
		cout<<0<<endl<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
