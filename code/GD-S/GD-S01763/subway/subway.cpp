#include<bits/stdc++.h>
using namespace std;
int gp[4700][4700];
int main()
{
	memset(gp,0x3f,sizeof gp);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q,st,ed;
	cin>>c>>n>>m>>d>>q;
	const int m_m_n=m+m+n;
	for(int i=1;i<=m_m_n;i++)
		gp[i][i]=0;
	for(int i=1,w;i<=m;i++)
		cin>>w,
		gp[i][m+i]=w,
		gp[m+i][i]=w;
	for(int i=1,j,v,w;i<=n;i++)
	{
		cin>>j;
		while(j--)
			cin>>v>>w,
			gp[m+m+i][m+v]=w,
			gp[m+i][m+m+i]=w;
	}
	for(int k=1;k<=m_m_n;k++)
		for(int i=1;i<=m_m_n;i++)
			for(int j=1;j<=m_m_n;j++)
				if(gp[i][j]>gp[i][k]+gp[k][j])
					gp[i][j]=gp[i][k]+gp[k][j];
	while(q--)
		cin>>st>>ed,
		cout<<gp[st][ed]<<"\n";
	return 0;
}
