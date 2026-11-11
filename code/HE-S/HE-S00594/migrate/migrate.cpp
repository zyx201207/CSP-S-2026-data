#include<bits/stdc++.h>
using namespace std;
int n,d;
int c,t;
int x[2000005];
int mins;
int s;
int f1=1;
int f=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		f=0;
		f1=1;
		cin>>n>>d;
		if(n==1&&n==2&&n==3)
		{
			cout<<"0";
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
			if(j>2){
			if(x[j]-x[j-1]!=x[j-1]-x[j-2])
			{
				f1=0;
			}
		}
		}
		
		
		for(int j=1;j<=n;j++)
		{
			if(d>=x[j]-x[1]&&d>=x[n]-x[j])
			{
				cout<<"0"<<endl;
				f=1;
				break;
			}
		}
		if(f==1)
		{
			continue;
		}
		
		if(f1==1)
		{
				if(n%2==0)
				{
					if(n==4)
					{
						s=1;
					}else{
					s=(n+1)*((n-4)/2+1)-(4+n)/2*n;}
					cout<<s<<endl;
				}else
				{
					n=n-1;
					if(n==4)
					{
						s=2;
					}else{
					s=(n+1)*((n-4)/2+1)-(4+n)/2*n+1;}
					cout<<s<<endl;
				}
				continue;
		}else{
		
		cout<<"1";}
	}
	return 0;
}
