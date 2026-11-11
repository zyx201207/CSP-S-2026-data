#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		int x,y;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
		}
		if(((n+1)/2-(k+1)/2+1)%2==0) cout<<((n+1)/2-(k+1)/2+1)/2<<'\n';
		else cout<<((n+1)/2-(k+1)/2+1)/2+1<<'\n';
	}
}
