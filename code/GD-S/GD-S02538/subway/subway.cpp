#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
int w[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;++j)
		{
			int a,ti;
			cin>>a>>ti;
		}
	}
	for(int i=0;i<q;++i)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)
		{
			cout<<0<<"\n";
		}
		else
		{
			cout<<w[x-1]+w[y-1]+10<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
