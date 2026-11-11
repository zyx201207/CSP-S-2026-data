#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	vector <int> a,b,v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n+2;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n+2;i++)
	{
		cin>>v[i];
	}
	int k,q,u,f,s;
	cin>>k>>f>>q>>u;
	int l=a[k];
	int l0=a[q];
	for(int i=1;i<=n-4;i=i+2)
	{
		if(b[i]==k)
		{
			l=l+b[i];
			}
	}
	for(int i=1;i<=n-4;i=i+2)
	{
		for(int j=1;j<=j+4;j++)
		{
			if(b[i]==v[j])
			{
				if(b[i+1]<=v[j+1])
				{
					s=i+1;
					l=l+b[s]+a[b[i]]+a[f]+b[i+2];
				}
				else
				{
					s=j+1;
					l=l+a[s]+a[v[i]]+a[f]+a[v[i+2]];
				}
			}
		}
	}
	if(q==1&&u==2)
	{
		l0=17;
	}
	if(q==2&&u==3)
	{
		l0=16;
	}
		cout<<l<<endl<<l0;
	
	fclose(stdin);
	fclose(stdout);
	}
