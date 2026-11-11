#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int p[N]={},l[N]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=-1;
	cin>>n>>m;
	int a[n],st[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[n];	
	}for(int i=0;i<n;i++)
	{
		int k=n-1-i;
		if(t==-1||p[a[k]]==0)
		{
			t++;
			st[t]=a[k];
			for(int j=0;j<=t;j++)
			{
				l[st[j]]++;
			}
		}else
		{
			while(st[t]!=a[k])
			{
				t--;
			}
			for(int j=0;j<=t;j++)
			{
				l[st[j]]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<l[i]<<" ";	
	}
	cout<<endl;
	return 0;
}
