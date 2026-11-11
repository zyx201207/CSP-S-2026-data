#include<bits/stdc++.h>
using namespace std;

int aaaaa,n,m,c,t;
int m1[500200],n1[501][500200][2]={0};

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>aaaaa>>n>>m>>c>>t;
	
	for(int i=0;i<m;i++)
		cin>>m1[i];
	
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		for(int j=0;j<a;j++)
		{
			cin>>n1[i][j][0];
			cin>>n2[i][j][1];
		}
	}
	
	
	for(int i=0;i<t;i++)
	{
		int a,b,ma=0;
		cin>>a>>b;
		ma+=m1[a-1];
		for(int j=0;j<n;j++)
		{
			int k=0,o=0;
			while(n1[j][k][0]!=0)
			{
				if(n1[j][k][0]==a)
					o++;
				if(n1[j][k][0]==b)
				{
					o++;
					break;
				}
			}
			if(!o%2)
			{
				ma+=n1[j][k][1];
				ma+=m1[b];
			}
		}
		cout<<ma;
	}
	
	return 0;
}
