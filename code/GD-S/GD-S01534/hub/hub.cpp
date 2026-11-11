#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int u[N],w[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u[i]>>w[i];
		cout<<k-1<<"\n";
	}
	return 0;
}

