#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[505],t[205];
deque<int>q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int le=q.size();
			bool find=false;
			for(int f=1;f<=le;f++)
			{
				int top=q.front();
				q.pop_front();
				if(top==a[j])
				{
					while(q.back()!=top) q.pop_back();
					q.push_back(a[j]);
					find=true;
					break;
				}
			}
			if(find==false) q.push_back(a[j]);
		}
		while(!q.empty()) 
		{
			t[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<endl;
	}
	return 0;
}

