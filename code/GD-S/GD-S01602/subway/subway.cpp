#include<bits/stdc++.h>

using namespace std;
int c,n,m,d,q,w[500005],k[505],ki[505][500005][2],rxy[100005][2],ans;

void dfs(int rx,int ry,int ansa,int)
{
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freoepn("subway.out","w",stdout);
	
	cin>>c>>n>>M>>d>>q;
	for (int i=0;i<m;i++)
	{
		cin >> w[i];
	}
	for (int i=0;i<n;i++)
	{
		cin >> k[i];
		for (int j=0;j<k[i];j++)
		{
			cin>>ki[i][j][0]>>ki[i][j][1];
			}	}
	for(int i=0;i<q;i++)
	{
		cin>>rxy[i][0]>>rxy[i][1];
		
	}
	cout >> ans;
	fclose(stdin);
	fclose(stdout);
}
