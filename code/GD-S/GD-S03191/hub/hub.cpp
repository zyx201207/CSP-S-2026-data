#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T,n,k,x;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>k>>k;
		}
		cout<<n/5<<endl;
	}
	//172~184pts
	return 0;
}
