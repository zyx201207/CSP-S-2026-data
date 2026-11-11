#include<bits/stdc++.h>
using namespace std;

	long long n,m;
	cin>>n>>m;
	long long a[1000005],ans[1000005];
	stack c[100005];
	bool b[1000005]=false;

int main()
{

	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	//

	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{	
			if(b[a[i]]==0)
			{
				c.push(a[i]);
				b[a[i]]=1;
			}
			else
				while(c.back()!=a[i])
				{
					b[c.back()]=0;
					c.pop();
				}
			
		}
		while(!c.empty())
		{
			ans[c.back()]++;
			c.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	
	return 0;

}
