#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,cnt;
int u[1000005],v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u[i]>>v[i];
			cnt+=v[i]-u[i];
		}
		cout<<cnt/(n-1)<<endl;
	}
	return 0;
}
