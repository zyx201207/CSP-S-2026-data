#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long aa[m][m];
	for(int x=0;x<m;x++)
		for(int y=0;y<m;y++)
			aa[x][y]=INT_MAX;
	int w[m];
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++)
	{
		cin>>k;
		long long a[k],t[k];
		for(int j=0;j<k;j++)cin>>a[j]>>t[j];
		for(int x=0;x<k;x++)
			for(int y=0;y<k;y++)
				aa[a[x]-1][a[y]-1]=min(aa[a[x]-1][a[y]-1],t[x]+t[y]);
	}
	for(int x=0;x<m;x++)
		for(int y=0;y<m;y++)
			for(k=0;k<m;k++)
				if(aa[x][k]+aa[y][k]<aa[x][y])
				aa[x][y]=aa[x][k]+aa[y][k];
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		cout<<aa[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
