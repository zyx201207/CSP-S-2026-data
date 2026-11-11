#include<bits/stdc++.h>
using namespace std;
long long c,t,a[6009][6009],b[6009][6009];
long long n,d;
long long sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		
		cin>>n>>d;
		int x[500009];
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int dd=1,nn=0;
		while(dd<n)
		{
			int bj=x[dd]+d,sum=nn;
			for(int i=dd+1;i<=n;i++)
			{
				if(x[i]<=bj)
				{
					sum++;
				}
				if(x[i]>bj)
				{
					dd=i-1;
					break;
				}
			}
			if(sum==2)
			{
				bj=x[dd]+d,sum=nn;
				for(int i=dd;i<=n;i++)
				{
					if(x[i]<=bj)
					{
						sum++;
					}
					if(x[i]>bj)
					{
						dd=i-1;
						break;
					}
				}
				if(sum>=2)
				{
					cout<<sum-1<<"\n";
					break;
				}
				if(sum==1)
				{
					nn++;
				}
			}
			else if(sum>=3)
			{
				cout<<0<<"\n";
				break;
			}
		}
	}
	return 0;
}

