#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[100005],k[100005],a[5005][5005],t[5005][5005],x,y;
	while(q--)
	{
		int maxn=-1;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				maxn=max(maxn,a[i][j]);
				cin>>t[i][j];
			}
		}
		cin>>x>>y;
		
		
	}
} 
