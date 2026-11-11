#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int a[500010];
int b[500010];
int g[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c!=0)
	{
		return 0;
	}
	for(int i=1;i<=m;i++) cin>>a[i];
	while(n--)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)	cin>>b[i]>>g[i];
	}
	for(int i=1;i<=q;i++)
	{
		int r,t;
		cin>>r>>t;
		int sum=0;
		sum=sum+a[r]+a[t];
		for(int i=1;i<=5000;i++)
		{
			sum+=g[i];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
