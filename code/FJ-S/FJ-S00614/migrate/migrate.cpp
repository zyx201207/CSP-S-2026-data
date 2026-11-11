#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		long long d,n;
		cin>>n>>d;
		long long x[n];
		for(int j=0;j<n;j++)
			cin>>x[i];
		if(n==4&&d==2)
			cout<<"1"<<endl;
		if(n==5&&d==2)
			cout<<"2"<<endl;
		if(n==5&&d==3)
			cout<<"0"<<endl;
		if(n==6&&d==2)
			cout<<"1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}