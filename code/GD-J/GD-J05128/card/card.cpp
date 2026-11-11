#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],f[300010],v[300010];
stack <int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]])
			{
				while(!s.empty()&&s.top()!=a[j])
				{
					f[s.top()]=0;
					s.pop();
				}
				s.pop();
			}
			s.push(a[j]);
			f[a[j]]=1;
		}
//		cout<<'*'<<i<<endl;
		while(!s.empty())
		{
//			cout<<s.top()<<endl;
			v[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
