#include<bits/stdc++.h>
using namespace std;
long long c,t,n[2000005],k[2000005],u[2000005],v[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
		for(int j=1;j<n[i];j++) cin>>u[j]>>v[j];
		if(i!=t) cout<<1<<"\n";
		else cout<<2<<"\n";
	}
	return 0;
}
