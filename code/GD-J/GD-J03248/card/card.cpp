#include <bits/stdc++.h>
using namespace std;
int dian[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[m];
	vector <int> b;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int z=1;z<=n;z++)
	{
		int k=m,wei=z,ch=0;
		while(k>0)
		{
			b.push_back(a[wei]);
			ch++;
			wei++;
			int c=-1;
			for(int i=0;i<=ch-1;i++)
			{
				if(b[i]==a[wei])
				{
					c=i;
					continue;
				}
			}
			if(c!=-1)
			{
				for(int i=c+1;i<=ch;i++)
				{
					b.pop_back();
				}
			}
		}
		for(int i=0;i<=ch-1;i++)
		{
			dian[b[i]]++;
		}
		//-----------------------------
		for(int i=ch-1;i>=0;i--)
		{
			b.pop_back();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<dian[i]<<" ";
	}
	return 0;
}
