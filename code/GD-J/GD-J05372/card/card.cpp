#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],f1[10005],f2[10005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(f1,0,sizeof(f1));
		stack<long long> s;
		for(int j=i;j<=n;j++)
		{
			if(f1[a[j]]==0)
			{
				s.push(a[j]);
				f1[a[j]]=1;
			}
			else if(f1[a[j]]==1)
			{
				while(s.top()!=a[j])
				{
					f1[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			f2[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	cout<<f2[i]<<" "; 
	return 0;
}

