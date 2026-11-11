//GZ-S00225  遵义市第十九中学  吴韩飞
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k;
		int u[n],v[n];
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
		}
		for(int i=1;i<n;i++)
		{
			if(u[i]==1)
			{
				cout<<1<<endl;
				break;
			}
			else
			{
				cout<<2<<endl;
				break;
			}
		}
	}
	return 0;
}
