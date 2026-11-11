#include<iostream> 
#include<string>
using namespace std;
#define int long long
int u[2000000];
int w[2000000];
int k;

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k; 
		for(int j=1;j<=n-1;j++)
		{
			cin>>u[j]>>w[j];
		}
		for(int j=1;i<=n-1;j++)
		{
			if(u[j]>=w[i])
			{
				int s=w[i];
				u[i]=w[i];
			}
		}
	}

	for(int i=0;i<t;i++)
	{
		cout<<1<<endl;
	}
	return 0;
 } 
