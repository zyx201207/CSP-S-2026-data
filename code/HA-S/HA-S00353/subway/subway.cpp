#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[505];
int x[100005],y[100005];
int tim[100005];
int b[505][500005],t[505][500005];
int dq;
struct node{
	int w;
}a[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i].w;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>b[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		dq=x[i];
		tim[i]+=a[x[i]].w;
		if(b[i][1]==x[i])
		{
			dq=b[i][2];
			tim[i]+=t[i][1];
			if(dq>y[i])
			{
				tim[i]+=t[i][dq]+t[i-1][dq];
				dq=b[i+1][dq];
			}
			else if(dq<y[i])
			{
				tim[i]+=t[i][dq]+t[i+1][dq];
				dq=b[i+1][dq];
			}
			else
			{
				tim[i]+=a[y[i]].w;
				cout<<tim[i];
	
			}
		}
	}
	return 0;
}
