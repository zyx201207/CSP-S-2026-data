#include<bits/stdc++.h>
using namespace std;
int w[5000005];
int k[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin<<k[i];
		for(int j=1;j<=k[i];j++)
		{
			long long t;
			cin>>t;
			ans+=t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<w[l]+w[r]+ans<<endl;
	}
	return 0;
}
