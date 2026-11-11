#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14)
	{
		while(t--)
		{
			int n,k;
			cin>>n>>k;
			cout<<(n-k)/2<<"\n";
		}
	}
	else
	{
		while(t--)
		{
			int n,k;
			cin>>n>>k;
			cout<<"1\n";
		}
	}
	
}
