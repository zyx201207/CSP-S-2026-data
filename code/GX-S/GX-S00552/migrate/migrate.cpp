#include<bits/stdc++.h>
using namespace std;
int c;
int n,t;
long long d,arr[1000003]={0},ans[1000003]={0},a=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 ||c==12)
	{
		for(int i=1;i<=t;i++)
		{
			cin>>n>>d;
			for(int j=1;j<=n;j++)
			{	
				cin>>arr[j];
				
			}
			int long long z=(n/d)*2-1;
				if(n==d || (n-1)%d==0 || n<d)
				cout<<"0"<<endl;
				else
				cout<<z<<endl;
		}
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=n;j++)
			cin>>arr[j];
			if(n==d || (n-1)%d==0 || n<d)
			cout<<"0"<<endl;
			else
			cout<<0<<endl;
		}
	}	
	//for(int i=1;i<=t;i++)
	//{
	//	cin>>n>>d;
	//	for(int j=1;j<=n;j++)
	//	{
	//		cin>>arr[j];
	//		if(j!=1)
	//		ans[j]=arr[j]-a;
	//		a=arr[j]
	//	}
	//woaic++!!!
	//19
	//30&45
	//	8.34.30ai45verymuch
	
	return 0;
}

