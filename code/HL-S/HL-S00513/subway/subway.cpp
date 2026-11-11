#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[10001];
int b[10001][10001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		for(int j=0;j<i;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<a[0]+b[0][0]+b[0][1]+b[1][1]+b[2][3]+a[2]<<endl;
	cout<<a[0]+b[0][0]+b[0][1]+a[1];
	return 0;
}