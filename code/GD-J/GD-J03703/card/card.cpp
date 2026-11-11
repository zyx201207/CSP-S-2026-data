#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];  
int cnt;
int b[500005];
int box[500005];
int check(int i)
{
	for(int j=1;j<=cnt;j++)
	{
		if(b[j]==i) return j;
	}
	return 0;
}
int yj()
{
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		cnt=0;  
		for(int j=i;j<=n;j++)
		{
			int x=check(a[j]);
			if(x==0)
			{
				cnt++;
				b[cnt]=a[j];
			} 
			else
			{
				for(int y=x;y<=cnt;y++)
				{
					b[y]=0;
				}
				cnt=x;
				b[cnt]=a[j];  
			}
		}	
		for(int j=1;j<=cnt;j++)
		{  
			box[b[j]]++;
		} 
	}
	return 0;  
}
int main()
{  
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	yj();
	for(int i=1;i<=m;i++)
	{
		cout<<box[i]<<' '; 
	}
	return 0;
}
