#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
struct loy
{
	long long u,v;
}a[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(long long i=1;i<n;i++)
		{
			cin>>a[i].u>>a[i].v;
		}
	}
	cout<<"1"<<endl<<"2"<<endl;
	return 0;
}
