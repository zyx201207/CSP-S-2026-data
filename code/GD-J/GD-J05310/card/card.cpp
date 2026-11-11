#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],c[100010];
void bfs(int i)
{
	queue<int> p;
	for(int j=i;j<=n;j++)
	{
		if(p.empty()) p.push(a[j]);
		else
		{
			int w=p.front();
			p.pop();
			p.push(w);
			if(w==a[j])
			{
				while(!p.empty()) p.pop();
				p.push(a[j]);
				continue;
			}
			while(p.front()!=a[j]&&p.front()!=w)
			{
				int e=p.front();
				p.pop();
				p.push(e);
			}
			while(p.front()!=w) p.pop();
			p.push(a[j]);		
		}
	}
	while(!p.empty()) 
	{
		int w=p.front();
		c[w]++;
		p.pop();
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0; 
 } 
