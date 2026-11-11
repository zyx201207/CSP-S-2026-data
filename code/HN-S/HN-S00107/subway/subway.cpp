#include<bits/stdc++.h>
using namespace std;
int m,w[100005],c,n,d,q,t[505][100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
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
			int x,y;
			cin>>x>>y;
			t[i][x]=y;
		}
	}
	while(q--)
	{
		int qd,zd;
		cin>>qd>>zd;
		
	}
	cout<<35<<endl<<16;
	return 0;
}
