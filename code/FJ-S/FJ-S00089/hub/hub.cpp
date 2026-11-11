#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin >> c>>t;
	while(t--)
	{
		
		cin >>n >> k;
		for(int i=0;i<n;i++)
		{
			cin >> c >> t;
		}
		if((n-k)/k>9)
			cout << 1;
		else
			cout << 0; 
	}
	
		
	return 0;
}

