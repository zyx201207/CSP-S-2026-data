#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n1[11000][11000];
ll c,n,m,d,q,m1[1000100],k,x[1000100],t[1000100],a,b,gg,x1,t1,x2,t2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>m1[i];
	}
	int bb;
	for(int i=1;i<=n;i++)
	{
		cin>>k>>x1>>t1;
		bb=x1;
		for(int j=2;j<=k;j++)
		{
			cin>>x2;
			n1[x1][x2]=t1;
			n1[x2][x1]=t1;
			cin>>t1;
			if(j==k)
			{
				x1=b;	
			}
			else
			{
				x1=x2;
			}
			
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<n1[i][j];
		}
		cout<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		for(int oo=a;oo<b;oo++)
		{
			for(int j=b;j>a;j--)
			{
				if(n1[a][j]!=0)
				{
					gg+=n1[a][j];
					a=j;
					continue;	
				}
			}
		}
		for(int i=a;i<=b;i++)
		{
			gg+=m1[i];
		}
		cout<<gg<<endl;
		gg=0;
	}
	
	return 0;
}

