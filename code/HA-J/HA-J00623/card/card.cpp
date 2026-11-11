#include <bits/stdc++.h>
using namespace std;
struct gamesss
{
	long long v=0,id=0;
}p[500000+10];
int b[500000+10],a[500000+10],t[300000+10];
long long n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long k=0;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int q=1;q<=n;q++)
	{	
		for(int i=q;i<=n;i++)
		{
			if(p[a[i]].v==0)
			{
				p[a[i]].v=1;
				k++;
				p[a[i]].id=k;
				b[k]=a[i];
			}	
			else if(p[a[i]].v==1)	
			{	
				k=p[a[i]].id;
				b[k]=a[i];
			}
		}
		for(int i=1;i<=k;i++)	t[b[k]]++;
	}
	for(int i=1;i<=m;i++)	cout<<t[i]<<" ";
	
	return 0;
} 
