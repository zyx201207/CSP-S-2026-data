#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int a[500010];
int b[500010];
int m;
int u,f,v;
int x;
int g;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cin>>n>>k;
	for(int i=1; ;i++)
	{
		if(n==2*m+1)
		{
			u=i;
			v=i+1;
			u=i-m;
		}
		cin>>a[i];
		for(int j=1; ;j++)
		{
			cin>>b[j];
			if(g==n+(n-1)||g==u+v)
			{
				return 0;
			}
			x=min(a[i],b[j]);
		}
	}
	cout<<1<<endl;
	cout<<2<<endl;
	return 0;
 } 
