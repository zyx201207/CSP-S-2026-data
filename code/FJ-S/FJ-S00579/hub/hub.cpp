#include<iostream>
using namespace std;
long long x[2000001];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		if(n==k)cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
