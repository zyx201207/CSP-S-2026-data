#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	srand(time(0));

	int c,t;cin>>c>>t;
	while(t--)
	{
		int n;cin>>n;
		cout<<n+rand()%n<<'\n';
	}
	return 0;
 } 
