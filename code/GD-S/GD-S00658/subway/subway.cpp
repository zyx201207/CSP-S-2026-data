#include<bits/stdc++.h>
int w[500005];
int a[500005];
int t[500005];
int h[500005];
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q,s;
	cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>t[j];
			s++;
		}
	}
	cout<<t[1]*s;
	
	fclose(stdin);
	fclose(stdout);
 } 
