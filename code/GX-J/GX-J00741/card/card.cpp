
#include<bits/stdc++.h>
using namespace std;
int n,m,f[300005];
string a,v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a+=(char)x;
	}
	for (int i=0;i<n;i++)
	{
		v=a;
		int x=n;
		for (int j=i;j<x;j++)
		{
			for (int t=j+1;t<x;t++)
			{
				if (v[j]==v[t])
				{
					x-=t-j;
					v.erase(j+1,t-j);
				}
			}
		}
		for (int j=i;j<x;j++)
		{
			f[v[j]+0]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
