#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
map<int,int>mm,m1,m3;
void f(int j)
{
	m1=m3;
	deque<int>d;
	for(int i=j;i<=n;i++)
	{
		if(m1[a[i]]==1)
		{
			while(!d.empty()&&d.back()!=a[i])
			{
				m1[d.back()]=0;
				d.pop_back();
			}
			if(!d.empty())
			{
				m1[d.back()]=0;
				d.pop_back();
			}
		}
		m1[a[i]]=1;
		d.push_back(a[i]);
	}
	for(int i=0;i<d.size();i++)
	{
		mm[d[i]]++;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mm[i]<<' ';
	}
	return 0;
}
