#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
long long v[N][N]={0};
long long w[N]={0};

long long dist[N][N]={500000};

int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			v[i][a]=t; 
			
		}
		
	} 
	while(q--)
	{
		
		dist[N][N]={500000};
		int st,en;
		cin>>st>>en;
		
		for(int i=1;i<=d;i++) 
		{
			
			for(int j=1;j<=d;j++)
			{
				dist[st][en]=min(w[st]+v[i][st]+w[en]+v[j][en],dist[st][en]);
			}
			
		}
		cout<<dist[st][en];
	} 
	
	
	
	
	
}
