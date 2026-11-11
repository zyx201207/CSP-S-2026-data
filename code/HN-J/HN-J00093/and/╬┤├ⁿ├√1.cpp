#include<bits/stdc++.h>
using namespace std;

int b[500005];
vector<int>desktop,a;

int main()
{
	freopen("C:/Users/Administrator/Desktop/card/card4.in","r",stdin);
//	freopen("C:/Users/Administrator/Desktop/.txt","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m,o;
	bool flag;
	memset(b,0,sizeof(b));
	cin>>n>>m;
	flag=true;
	cin>>o;
	a.push_back(o);
	for(int i=1; i<n; i++)
	{
		cin>>o;
		a.push_back(o);
		if(a[i]<a[i-1])
		{
			flag=false;
		}
	}
	if(flag)
	{
		for(int i=0; i<m; i++)
		{
			cout<<i+1<<" ";
		}
		return 0;
	}
	for(int too=0; too<n; too++)
	{
		desktop.clear();
		for(int i=0; i<n; i++)
		{
			if(!desktop.empty())
			{
				for(int j=0; j<=desktop.size(); j++)
				{
					if(desktop[j]==a[i])
					{
						desktop.erase(desktop.begin()+j,desktop.end());
					}
				}
			}
			desktop.push_back(a[i]);
		}
		for(auto e:desktop)
		{
			b[e]++;
		}
		a.erase(a.begin());
	}
	for(int i=1; i<=m; i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}

