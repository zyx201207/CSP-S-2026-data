#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],b[500005];
bool ch(int na,int ca)
{
	for(int i=1;i<=ca;i++)
	{
		if(na==b[i]) return false;
	}
	return true;
 } 
int ch2(int na,int ca)
{
	for(int i=1;i<=ca;i++)
	{
		if(na==b[i]) return i;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int c=0;
		for(int j=i;j<=n;j++)
		{
			if(ch(a[j],c))
			{
				b[++c]=a[j];
			}
			else
			{
				int cd=0;
				for(int k=ch2(a[j],c);k<=c;k++)
				{
					cd++;
					b[k]=0;
				}
				c-=cd;
				b[++c]=a[j];
			}
		}
		for(int j=1;j<=c;j++)
		{
			s[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
 } 
