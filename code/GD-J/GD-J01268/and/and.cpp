#include <bits/stdc++.h>
using namespace std;
int n,m,a,b[200015],maxn,p,z,c;
vector<int> v[200015];
vector<int> id[200015];
int num;
int main()
{
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		a=b[i];
		for(int j=1;a>0;j++)
		{
			maxn=max(maxn,j);
			if(a%2==1)
			{
				v[j].push_back(i);
			}
			a/=2;
		}
	}

	for(int i=maxn;i>=0;i--)
	{
		if(int(v[i].size())==m)//1
		{
			//cout<<i<<" ";
			for(int j=0;j<int(v[i].size());j++)
			{
				//cout<<b[v[i][j]]<<" ";
				if(num==0)
				{
					num=b[v[i][j]];
				}
				num&=b[v[i][j]];
			}
			break;
		}
		
		if(int(v[i].size())>m)//2
		{
			for(int j=0;j<int(v[i].size());j++)
			{
				if(j==0)
				{
					z=b[v[i][j]];
				}
				if(j<m)
				{
					z&=b[v[i][j]];
				}
				id[c].push_back(v[i][j]);
			}
			
			for(int k=i-1;k>=0;k--)
			{
				if(v[k].size()>=m)
				{
					for(int j=0;j<int(id[c].size());j++)
					{
						for(int l=0;l<int(v[k].size());l++)
						{
							if(id[c][j]==v[k][l])
							{
								id[c+1].push_back(id[c][j]);
								break;
							}
						}
					}
					c++;
				}
				
				if(id[c].size()==m)
				{
					for(int j=0;j<int(v[k].size());j++)
					{
						//cout<<b[v[i][j]]<<" ";
						if(num==0)
						{
							num=b[v[k][j]];
						}
						num&=b[v[k][j]];
					}
					num=max(num,z);
				}
			}
			break;
		}
	}
	cout<<max(num,z);
	return 0;
} 
