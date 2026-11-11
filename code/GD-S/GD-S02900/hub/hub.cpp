#include<bits/stdc++.h>
#define int long long
#define fre freopen("hub.in","r",stdin),freopen("hub.out","w",stdout)
using namespace std;
int c,t,n,k;
signed main()
{
	fre;
	for(cin>>c>>t;t;t--)
	{
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++) cin>>u>>v;
		cout<<n/k<<endl;
	}
	return 0;
}
