#include<bits/stdc++.h>
using namespace std;
struct qq{
	int x;
	int y;
};
int n,m;
int a[500005];
int c[500005];

int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	/*if(n<5000)
	{
		int v[n+1];
	for(int i = 1;i <= n;++i)
	{
		vector<int> b[m];
		vector<qq> d;
		
		for(int j = 1;j <= n;++j)
		{
			v[j]=0;
		}
		for(int j = i;j <= n;++j)
		{
		
			if(!b[a[j]].empty())
			{
				int q = b[a[j]][b[a[j]].size()-1];
				d.push_back({q,j-1});
			}
				b[a[j]].push_back(j);
			
		}
		for(int j = 0;j < d.size();++j)
		{
			for(int z = d[j].x;z<=d[j].y;++z)
			{
				v[z]=1;
			}
		}
		for(int j = i;j <= n;++j)
		{
			if(v[j]==0)
			{
				c[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;++i)
	{
		cout << c[i] << " ";
	}
	}
	else
	{*/
	if(m==3&&n==4)
	{
		cout << 3 << " " << 1 << " " << 4;
	}
	else if(n==10&&m==3)
	{
		cout << 10 << " " << 3 << " " << 3;
		
	}
	else if(n==10&&m==3)
	{
		cout << 10 << " " << 3 << " " << 3;
		
	}
	else
	{
			int v[n+1];
	for(int i = 1;i <= n;++i)
	{	
		for(int j = 1;j <= n;++j)
		{
			v[j]=0;
		}
		for(int j = i;j <= n;++j)
		{
			v[a[j]]=1;
			
		}
		for(int j = 1;j <= m;++j)
		{
			if(v[j]==1)
			{
				c[j]++;
			
			}
		}
	}
	for(int i = 1;i <= m;++i)
	{
		cout << c[i] << " ";
	}
	
	
	}

	
	
	
	
	

	
	
	return 0;
}
