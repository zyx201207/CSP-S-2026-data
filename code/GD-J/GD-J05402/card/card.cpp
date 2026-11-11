#include<bits/stdc++.h> 
using namespace std;
long long a[200005],n,m,c[200005],ans[2000005];
stack <int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
					if(c[a[j]]==1) 
				{
					while(s.top()!=a[j]) {c[s.top()]=0;s.pop();}
					s.pop(); 
					c[a[j]]=0;
				}
					s.push(a[j]);
					c[a[j]]++;	
			}
			while(!s.empty())
			{
				ans[s.top()]++;
				c[s.top()]=0;
				s.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
