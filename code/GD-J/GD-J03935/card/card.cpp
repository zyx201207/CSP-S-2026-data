#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+10;

int n, m;
int a[MAXN];

int pos[MAXN];
int l[MAXN];

stack<int> s;
unordered_map<int, int> mp;
			
int ans[MAXN];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n <= 1e4)
	{
		for(int b=1;b<=n;b++)
		{
			mp.clear();
			for(int i=b;i<=n;i++)
			{
				bool f = mp[a[i]];
				if(f){
					while(!s.empty() && s.top() != a[i]) mp[s.top()]--, s.pop();
				}
				else s.push(a[i]), mp[a[i]]++;
			}
			while(!s.empty())
			{
				ans[s.top()]++;
				s.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			l[i] = pos[a[i]];
			pos[a[i]] = i;
		}
		for(int i=1;i<=m;i++) cout<<pos[i]<<' ';
	}
	return 0;
}
