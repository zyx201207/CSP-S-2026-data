#include<bits/stdc++.h>
using namespace std;
int p[50001],q[30001],x[50001],y=1,z[30001]={0},n,m;
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
	cin>>p[i];}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
		{
			if(x[p[j]]==0)
			{
				x[p[j]]=y;
				q[y]=p[j];
				y++;
			}
			else
			{
				y=x[p[j]];
				for(int k=y+1;k<=j;k++)
				x[j]=0;
			}
			}
	for(int k=1;k<=y;k++)
	{z[q[k]]++;} 
	for(int i=0;i<n;i++)
	q[i]=0;
	for(int i=0;i<n;i++)
	x[i]=0;
}
	for(int i=1;i<=m;i++)
	if(z[i]!=0)cout<<z[i]<<' '; 
	return 0; 
}
