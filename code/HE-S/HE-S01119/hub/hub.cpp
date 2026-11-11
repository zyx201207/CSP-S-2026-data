#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,tmp;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for (int i=1;i<=n-1;i++)
		{
			cin>>tmp;
			cin>>tmp;
		}
		cout<<((n+1)/2+1-k+1+1+1)/4<<"\n";
	}
	return 0;
}
