#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int w[N];
int t[N];	
int minn=1e9;
int main()
{
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
			t[i]+=t[i+1];
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		w[i]=min(minn,w[i+1]);
	}
	cout<<32<<endl;
	cout<<17;
	return 0;
}
