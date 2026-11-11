#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e9;
struct subway
{
	int a,t;
};
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++)cin>>w[i];
	cin>>k;
	subway subway[k+1];
	for(int i=0;i<k;i++)
	{
		cin>>subway[i].a>>subway[i].t;	
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int t=w[x-1]+w[y-1]+subway[x].t;
		for(int i=0;i<n;i++)
		{
			if(subway[i].a==x)t+=subway[i].t;
			if(subway[i].a==y)t+=subway[i].t;
		}
		cout<<t<<endl;
	}
	
	return 0;
}
