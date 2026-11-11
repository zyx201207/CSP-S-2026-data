#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],c[N],cnt[N];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		q.push(i);
		if (c[a[i]])
		{
			for (int j=q.front();j<=i;j++)
			{
				c[j]=0;	
			}
		}
		c[a[i]]++;
		int cnt=0;
		for (int j=1;j<=i;j++)
		{
			if (c[j])cnt++;
		}
		cout<<cnt<<" ";
		q.pop();	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
