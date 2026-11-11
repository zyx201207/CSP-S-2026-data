#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t;
	cin>>t;
	int n,m;
	for(int i=1;i<=t;i++)
	{
	int a,b;
		cin>>n>>m;
		for(int l=1;l<n;l++)
		{
			cin>>a>>b;
		}
		cout<<ceil((n-m)*1.0/(m*2.0))<<endl;
	}
	return 0;
}
