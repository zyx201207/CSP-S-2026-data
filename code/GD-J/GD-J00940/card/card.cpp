#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("card.in",'r',stdin);
	freopen ("card.out",'w',stdin);
	int n,m;
	cin>>n>>m;
	int a[n],b[m]={0};
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;i++)
	{
		vector <int> q;
		int qt=0;
		bool mt=true;
		for (int j=i;j<n;j++)
		{
			for (int k=0;k<qt;k++)
			{
				if (q[k]==a[j])
				{
					mt=false;
					for (int l=k;l<qt;l++)
					{
						q.pop_back();
						qt--;
					}
					break;
				}
			}
			if (mt)
			{
				q.push_back (a[j]);
				qt++;
			}
			mt=true;
			if (j==n-1)
			{
				for (int k=0;k<qt;k++)
				{
					b[q[k]-1]++;
				}
			}
		}
	}
	for (int i=0;i<m;i++)
	{
		if (b[i]!=0)
		{
			cout<<b[i]<<' ';
		}
	}
	fclose (stdout);
	fclose (stdout);
	return 0;
}
