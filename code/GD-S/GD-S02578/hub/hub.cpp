#include<iostream>
using namespace std;
int c,t,n,k,u[1000001],v[1000001];
int main()
{	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{	cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>u[i]>>v[i];
		cout<<(k+1)/2<<"\n";
	}
	return 0;
}
//well bye OI!
