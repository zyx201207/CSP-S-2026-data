#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(nullptr);
using ll=long long;
const int N = 5e5+10;
int n,m;
int a[N];
map<int,int> s;
map<int,int> key;
map<int,int> cnt;
void init()
{
	s.clear();
	key.clear();
}
void clean(int x,int now)
{
	for(int i=now;i>=x;i--)
	{
		key.erase(s[i]);
		s.erase(i);
	}
}
void show()
{
	map<int,int> res;
	map<int,bool> flag;
	flag.clear();
	res.clear();
	for(int i=1;i<=int(s.size());i++)
	{
		if(!flag[s[i]])
		{
			cnt[s[i]]++;
			flag[s[i]]=true;
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		init();
		for(int i=k;i<=n;i++)
		{
			if(key[a[i]]!=0)
			{
				clean(key[a[i]],i);
			}
			key[a[i]]=s.size()+1;
			s[s.size()+1]=a[i];
		}
		show();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
}
signed main()
{
	ios;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	solve();
	return 0;
}

