#include<bits/stdc++.h>//ÀîÕþÐù GZ-J00435
using namespace std;
const int maxn = 1e8+325;
long long n,m;
int a[maxn],temp[maxn],ans[maxn];
queue<int> t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			temp[a[j]]++;
			if(temp[a[j]]>1)
			{
				while(!t.empty())
				{
					t.pop();
				}
				memset(temp,0,sizeof(temp));
				t.push(a[j]);
				temp[a[j]] = 1;
			}
			else
			{
				t.push(a[j]);
			}
		}
		while(!t.empty())
		{
			ans[t.front()]++;
			t.pop();
		}
		memset(temp,0,sizeof(temp));
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
