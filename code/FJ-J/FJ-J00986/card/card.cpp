#include<bits/stdc++.h>
using namespace std;
long long a[500100],c[500100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		bool b[500010]={};
		stack<long long> s;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]!=0)
			{
				while(s.top()!=a[j])
				{
					b[s.top()]=0;
					c[s.top()]--;
					s.pop();
				}
			}
		    else
			{
				b[a[j]]=1;
				c[a[j]]++;
				s.push(a[j]);
			}
		} 
		
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
