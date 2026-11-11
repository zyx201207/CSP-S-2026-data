#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x[500005],b[300005],maxx=INT_MIN;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	stack<int> c;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		if(x[i]>maxx)
		maxx=x[i];
	}
	for(int j=0;j<n;j++){
		while(!c.empty()) c.pop();
		for(int s=0;s<5000;s++) a[s]=0;
		for(int i=j;i<n;i++)
		{
			if(a[x[i]]>1)
			{
				while(!c.top()==x[i])
				{
					c.pop();
				}
				c.pop();
				a[x[i]]--;
			}
			c.push(x[i]);
			a[x[i]]++;
		}	
		for(int i=0;i<c.size();i++)
		{
			b[c.top()]++;
			c.pop();
		}
	}

	for(int i=0;i<=maxx;i++)
	{
		if(b[i]!=0)cout<<b[i]<<" ";
	}
}

