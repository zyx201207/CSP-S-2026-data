#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10,M=1e5*3+10;
int n,m;
int a[N];
bool b[M];
int t[M],s[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++)
		{
			b[i]=false;
		}
		for(int i=k;i<=n;i++)
		{
			if(!b[a[i]])
			{
				b[a[i]]=true;
				t[a[i]]=i;
			}
			else
			{
				for(int j=t[a[i]]+1;j<i;j++)
				{
					b[a[j]]=false;
				}
				t[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(b[i]) s[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}
