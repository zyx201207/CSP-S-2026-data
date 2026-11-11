//GZ-S00225  遵义市第十九中学  吴韩飞
#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i]-a[j]==3)
				{
					sum++;
				} 
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;	
	
} 
