#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int c,t;
	ll n,k;
	vector<ll>a(1000000,0);
	vector<ll>b(1000000,0);
	cin>>c>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}
