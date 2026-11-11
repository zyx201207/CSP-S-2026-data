#include <bits/stdc++.h>
using namespace std;
int hh[300005];	
int a[500005]={0};
void op(int k,int n)
{
	for(int i = k;i <= n;i++)
	{
		if(hh[a[i]] != 0)
		{
			for(int j = hh[a[i]];j < i;j++)
			{
				hh[a[j]] = 0;
			}
			hh[a[i]]=i;
		}
		else
		{
			hh[a[i]] = i;
		}
	} 
	return;	
	
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;

	int kl[m+5]={0};
	for(int i = 1;i <= n;i++)
	{
		cin >> a[n];
	}
	for(int i = 1;i <= n;i++)
	{
		op(i,n);
		for(int j = 1;j <= m;j++)
		{
			if(hh[i] != 0)
			{
				kl[i]++;
			} 
			hh[i]=0;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << kl[i] << " ";
	}
	return 0;
}
