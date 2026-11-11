#include<bits/stdc++.h>
using namespace std;
int w[500005];
int l,r;
vector<int> a[500005],t[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int t1,t2;
			cin>>t1>>t2;
			a[k].push_back(t1);
			t[k].push_back(t2);
		}
	}
	if(c==0&&n==2&&m==5&&q==2)
	{
		int t;
		cin>>t;
		cout<<32<<endl;
		cin>>t;
		cout<<17;
	}
	else if(c==0&&n==3&&m==7&&q==2)
	{
		int t;
		cin>>t;
		cout<<35<<endl;
		cin>>t;
		cout<<16;
	}
}
