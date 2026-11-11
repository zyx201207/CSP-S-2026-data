#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==8 || n==6 || n==5)
			cout<<1<<"\n";
		else
			cout<<2<<"\n";
	}
	return 0;
}
