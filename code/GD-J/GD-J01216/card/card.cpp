#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000001],x,y,b[10000001],t[10000001],vn[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		x=i;
		y=i;
		for(int j=i;j<n;j++)
		{
			y++;
			b[y]=a[j];
			for(int t=x+1;t<y;t++)
			{
				if(b[t]==b[y])
				{
					y=t;
					break;
				}
			}
		}
		for(int j=x+1;j<=y;j++)
		{
			vn[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<vn[i]<<" ";
	}
	return 0;
}
