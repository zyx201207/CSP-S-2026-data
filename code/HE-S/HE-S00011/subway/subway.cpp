#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500050],k[505],t[550][500050],a[505][500050],jh[2][100050];
long long ymn;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<n;i++)
		cin>>k[i];
	for(int i=1;i<n;i++)
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	for(int i=0;i<q;i++)
		cin>>jh[0][i]>>jh[1][i];
	
	
}
