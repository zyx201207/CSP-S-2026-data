#include <bits/stdc++.h>
using namespace std;
struct su{
	int sum;
}s[300000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500000];
	queue <int> b;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n ;i++)
	{
		for(int q=i; q<n;q++)
		{ 
			b.push(a[i]);
			for(int j=0; j<b.length(); j++)
			{
				if(a[q]==b[j])
				{
					for(int k=0; k<b.size()-1; k++)
					{
						b.pop();
					}
				}
			}
		}
		for(int w=0; w<b.size(); w++)
		{
			s[b.top].sum++;
			b.pop();
		}
	}
	for(int i=0; i<m; i++)
	{
		cout<<s[i].sum<<' ';
	}
	return 0;
}
