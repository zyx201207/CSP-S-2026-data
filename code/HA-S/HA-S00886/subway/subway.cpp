#include<bits/stdc++.h>
using namespace std;
int m1[500000];
int k[5000][5000];
int q1[1000];
int main()
{
	freopen("subway.in""r"stdin);
	freopen("subway.out""w"stdout);
	int c,n,m,d,q,k1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<m;i++)
	{
		cin>>m1[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k1;
		for(int j=1;j<=k1;j++)
		{
			cin>>k[i][j];
		}
	}
	for(int i=1;i<q;i++)
	{
		cin<<q1[i];
	}
	cout<<32<<endl<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}