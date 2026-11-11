#include<bits/stdc++.h>
using namespace std;

int n,m;
int mm[300123]={0},nn[300012];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>nn[i];
	
	for(int i=0;i<n;i++)
	{
		int nm[300001]={0};
		for(int j=i;j<n;j++)
		{
			int k=0;
			while(nm[k]!=0)
			{
				if(nn[j]==nm[k])
				{
					k++;
					while(nm[k]!=0)
					{
						nm[k]=0;
						k++;
					}
					k=-1;
					break;
				}
				k++;
			}
			if(k>=0)
				nm[k]=nn[j];
			
			int aaaa=0;
			while(nm[aaaa]!=0)
			{
				cout<<nm[aaaa]<<" ";
				aaaa++;
			}
			cout<<endl;
		}
		int a=0;
		while(nm[a]!=0)
		{
			mm[nm[a]]++;
			a++;
		}
	}
	
	for(int i=1;i<=m;i++)
		cout<<mm[i]<<" ";
	
	return 0;
}


