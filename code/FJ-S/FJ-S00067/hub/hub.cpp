#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long int n,k,u[10005],v[100005],minn=1000;
		cin>>n>>k;
		for(int j=1;j<=n;j++)
		{
			cin>>u[j]>>v[j];
			minn=min(minn,(v[j]-u[j]));
		}
			
		cout<<minn;
	 } 
} 
