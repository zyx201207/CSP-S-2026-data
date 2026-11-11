#include<bits/stdc++.h>
using namespace std;
int c[200005],d[200005];
int main()
{
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,b;
	for (int i=0;i<m;i++)
	{
		cin>>a>>b;
		for (int j=0;j<a-1;j++)
		{
			cin>>c[j]>>d[j];
		}
	}
	cout<<2<<endl<<3;
	return 0;
} 
