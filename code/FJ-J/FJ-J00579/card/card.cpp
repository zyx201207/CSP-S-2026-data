#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("card.in");
	ofstream fout("card.out");
	int n,m;
	fin>>n>>m;
	int c[n+1],ji[n+1],b[m+1],t[m+1];
	for(int i=1;i<=n;i++)
	{
		fin>>c[i];
		t[c[i]]=0;
		b[c[i]]=0;
	}
	for(int a=1;a<=n;a++)
	{
		for(int i=a;i<=n;i++)
		{
			ji[i]=c[i];
			if(t[c[i]]!=0)
			{
				for(int j=a;j<i;j++)
				{
					t[ji[j]]=0;
					ji[j]=0;
				}
			}
			t[c[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			if(t[i]!=0)
			{
				b[i]++;
				t[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		fout<<b[i]<<" ";
	}
	return 0;
}
