#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int x[10000000]={};
	int cnt=0;
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int j=1;j<=t;j++)
	{
	
	cin>>n>>d;
	
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
		for(int a=n;a>=1;a--)
	{
	
	for(int b=1;b<=n;b++)
	{
		if(sqrt(x[a])-sqrt(x[b])==3)
		{
			cnt++;
		}
	}
}
cout<<cnt<<endl;
}

	
	return 0;
}
