#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=2e5+7;
struct zm{
	int g;
	string z;
}t[INF];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].g>>t[i].z;
		for(int j=1;j<=t[i].g;j++)
		{
			a+=t[i].z;
		}
	}
	ll ans;
	ll b=a.size();
	ll c=(b/2);
	if(b%2==1)
	{
		for(int i=c+1;i<b;i++)
		{
			if()
		}
	}
	else
	{
		for(int i=c;i<b;i++)
		{
			
		}
	}
	cout<<a.size()/2;
	return 0;
}
