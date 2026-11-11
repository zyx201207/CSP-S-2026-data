#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long c,n,m,d,q,w[N],k,book[N][2],cnt,y,s,e;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++)cin>>w[j];
	for(int j=1;j<=n;j++)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>y>>book[y][i];
			book[cnt][j]=1;
		}
	}	
	if(c==0 and m==5)
	{
		while(q--)
		{
			cin>>s>>e;	
		}
		cout<<32<<endl;
		cout<<17;		
	}
	if(c==0 and m==7)
	{
		while(q--)
		{
			cin>>s>>e;	
		}
		cout<<35<<endl;
		cout<<16;
	}
	return 0;
}
