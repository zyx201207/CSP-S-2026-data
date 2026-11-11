#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5+55;
int a[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	memset(ans,0,sizeof(ans));
	int n,p;
	cin>>n>>p;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<int> vec;
	map<int,int> mp;
	vec.clear();
	mp.clear();
	for(int i = 1;i<=n;i++)
	{
		vec.clear();
		mp.clear();
		for(int j = i;j <= n;j++)
		{
			if(mp[a[j]] > 0)
			{
				mp[a[j]] --;
				while(vec.back() != a[j] && !vec.empty())
				{
					mp[vec.back()] --;
					vec.pop_back();
				}
			}
			else 
			{
				mp[a[j]] ++;
				vec.push_back(a[j]);
			}
		}
		for(auto v : vec)
		{
			ans[v] ++;
		}
		vec.clear();
	}
	for(int i = 1;i<=p;i++)
	{
		cout<<ans[i]<<" ";
	 } 
	 return 0;
 } 
