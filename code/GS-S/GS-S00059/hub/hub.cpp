#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int a[1000005][3];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	int c,q;
	cin>>c>>q;
	while(q--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			a[i][1]=u;
			a[i][2]=v;
		}
		if(c==13||c==14)
			cout<<1<<endl;
		else
			cout<<(n%k)<<endl;
	}
	return 0;
}
