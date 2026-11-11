#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+5;
int n,m;
int a[N];
int ans[N]; 
bool vis[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]<a[i-1])
		{
			flag=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		deque<int> q;
		memset(vis,0,sizeof(vis));
//		cout << "新的一局!"<<endl; 
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(q.size()&&q.back()!=a[j])
				{
					vis[q.back()]=0;
					q.pop_back();
				}
			}
			else
			{
				q.push_back(a[j]);
				vis[a[j]]=1;
			}
//			cout << "存活："<<endl; 
//			for(int k=1;k<=m;k++)
//			{
//				if(vis[k])
//				{
//					cout << k<<' ';
////					ans[k]++;
//				}
//			}
//			cout << endl;
		}
		for(int k=1;k<=m;k++)
		{
			if(vis[k])
			{
				ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<< ans[i]<<' ';
	}
	return 0;
}
//24分 
