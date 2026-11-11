#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
int n,m,w=0,w1=0;

cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	if(a[i]!=a[i-1])
	{
		w1++;
		w++;
	b[w1]=a[i];
	if(b[w1]<b[w1-1])
	{
	int x2=0;
	x2=b[w1];
	b[w1]=b[w1-1];
	b[w1-1]=x2;
	
}
}
}
  
if(w%2==1)
{
	int x=0,xi=0;
    for(int i=w/2;i>=1;i++)
    {
		x=b[w/2+1]-b[i]+x;
		xi++;
		if(x==m)
		{
			break;
		}
		if(x>m)
		{
			xi=xi-1;
			break;
		}
	}
	cout<<xi;
}
else
{
	int x=0,xi=0;
    for(int i=w/2-1;i>=1;i++)
    {
		x=b[w/2]-b[i]+x;
		xi++;
		if(x==m)
		{
			break;
		}
		if(x>m)
		{
			xi=xi-1;
			break;
		}
	}
	cout<<xi;
}
return 0;
}
