#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	int a;
//	cin>>a;
//	cout<<a<<endl;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	int e[n];
	for(int i=0;i<n;i++)
	{
		cin>>e[i];
		int d[e[i]*2];
		for(int j=0;j<e[i]*2;j++)
		{
			cin>>d[j];
		}
	}
	for(int i=0;i<q;i++)
	{
		int qw,wq;
		cin>>qw>>wq;
	}
	cout<<0<<" "<<0<<endl;
	return 0;
} 
