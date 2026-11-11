#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	deque<pair<pair<int,int>,char> > q;
	int n;
	cin>>n;
	int now = 1;
	for(int i = 1;i<=n;i++)
	{
		int x;
		char p;
		cin>>x>>p;
		q.push_back({{now,now + x - 1},p});
		now = now + x;
	}
	int ans = 0;
	while(q.size() > 1)
	{
		pair<pair<int,int>,char> a = q.front(),b = q.back();
		int lena = a.first.second - a.first.first + 1;
		int lenb = b.first.second - b.first.first +1;
		if(lena > lenb)
		{
			if(a.second != b.second)
			{
				ans += lenb;
				q.pop_back();
				pair<pair<int,int>,char> c = {{a.first.first + lenb,a.first.second},a.second};
				q.pop_front();
				q.push_front(c);
			}
			else
			{
				q.pop_back();
				pair<pair<int,int>,char> c = {{a.first.first + lenb,a.first.second},a.second};
				q.pop_front();
				q.push_front(c);
			}
		}
		else if(lena < lenb)
		{
			if(a.second != b.second)
			{
				ans += lena;
				q.pop_front();
				pair<pair<int,int>,char> c = {{b.first.first + lena,b.first.second},b.second};
				q.pop_back();
				q.push_back(c);
			}
			else
			{
				q.pop_front();
				pair<pair<int,int>,char> c = {{b.first.first + lena,b.first.second},b.second};
				q.pop_back();
				q.push_back(c);				
			}
		}
		else if(lena == lenb)
		{
			if(a.second != b.second)
			{
				ans += lena;
				q.pop_front();
				q.pop_back();
			}
			else
			{
				q.pop_front();
				q.pop_back();
			}
		}
	}
	cout<<ans<<endl;
	return 0;
 } 
