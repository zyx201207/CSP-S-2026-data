#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==13||c==14||c==0)
	{
		while(t--)
		{
			cin>>n>>k;int p;
			for(int i=1;i<n;i++)
			{
				int u,v;cin>>u>>v;
				if(u==1 && i!=1) p=i-1;
			}
			cout<<(p-k-1)/4+2<<'\n';
		}
	}
	return 0;
}
