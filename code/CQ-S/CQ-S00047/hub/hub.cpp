#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll t,n,k,u[20005],v[20005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&u[i],&v[i]);
		}
		cout<<k-1<<" ";
	}
	return 0;
}
