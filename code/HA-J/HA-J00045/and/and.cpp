#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	int n;
	int m;
	int q;
	int w;
	cin >>n;
	cin >>m;
	int q=0;
	int w=0;
	for(int i=1;i<=m;i++)
	{
		cin >>a[i];
	}
	if(m==1)
	{
		for(int k=1;k<=n;k++)
		{
			if(a[k]>q)
			{
				q=a[k];
			}
		}
	}
	if(m==2)
	{
		for(int k=1;k<=n;k++)
		{
			for(int t=k+1;t<n;t++)
			{
				w= a[k] and a[t];
				if(w>q)
				{
					q=w;
				}
			}
		}
	}
	if(m==n)
	{
		w=a[1] and a[2];
			for(k=2;k<m;k++)
			{
				w=w and a[k+1];
			}
			if(w>q)
				{
					q=w;
				}
}
	cout <<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

