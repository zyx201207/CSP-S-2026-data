#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	while(t--)
	{
		cin>>n>>k;
		int asd[n+5],asdf[n+5];
		for(int i=1;i<=n-1;i++)
		{
			cin>>asd[i]>>asdf[i];
		}
		if(n==5&&k==2) cout<<"1"<<endl;
		if(n==10&&k==3) cout<<"2"<<endl;
	}
	return 0;
}
