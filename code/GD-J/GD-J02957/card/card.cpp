#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5,N=5e5+5;
int n,m,t[M],a[N];
bool v[M];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(v,false,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]])
			{
				while(s.size()>0&&s.top()!=a[j])
				{
					v[s.top()]=false;
					s.pop();
				}
			}
			else
			{
				s.push(a[j]);
				v[a[j]]=true;
			}
		}
		while(s.size()>0)
		{
			t[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",t[i]);
}
