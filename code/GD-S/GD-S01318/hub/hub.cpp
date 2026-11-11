#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		cout<<d/n<<endl;
	}
 	return 0;
} 

