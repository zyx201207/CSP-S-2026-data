#include<bits/stdc++.h>
using namespace std;
long long c,T;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		long long n,k;
		cin>>n>>k;
		for(long long i=1;i<=n-1;i++)
		{
			long long u,v;
			cin>>u>>v;
		}
		if(k>=n)
		{
			cout<<"0"<<'\n';continue;
		}
		if(k>=n/2)
		{
			cout<<"1"<<'\n';continue;
		}
		
			long long m=n/2;
			cout<<(m-k+3)/4+1<<'\n';
	}
	return 0;
}
