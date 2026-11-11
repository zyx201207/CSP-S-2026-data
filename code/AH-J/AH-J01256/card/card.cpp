#include<bits/stdc++.h>
using namespace std;
long long int w[300010],n,m,a[500010],ss[500003];
queue <int> p;
bool f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		memset(f,0,sizeof(f));
		memset(ss,0,sizeof(ss));
		for(int j=i;j<n;j++)
		{
			if(f[a[j]]==1)
			{
				int u=0;
				while(p.front()!=a[j])
				{
					ss[u]=p.front();
					p.pop();
					u++;
				}
				while(!p.empty())
				{
					p.pop();
				}
				for(int v=0;v<u;v++)
				{
					p.push(ss[v]);
				}
				p.push(a[j]);
			}else{
				p.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(!p.empty())
		{
			w[p.front()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<w[i]<<' ';
	}
	return 0;
	
}
