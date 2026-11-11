#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nb
{
	ll x;
	char c;
};
vector<nb> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	for(int i = 1;i <= n;i++)
	{
		ll a;char b;cin >> a >> b;
		v.push_back((nb){a,b});
	}
	int i = 0,j = n-1;
	ll cnt = 0;
	while(i<j)
	{
		cout << cnt <<" ";
		if(v[i].c==v[j].c)
		{
			int x = v[i].x;
			v[i].x-=v[j].x;
			v[j].x-=x;
			if(v[i].x==0) i++;
			if(v[j].x==0) j--;
			continue;
		}
		if(v[i].x==v[j].x)
		{
			cnt+=v[i].x;
			v[i].c=0;
			v[j].c=0;
			i++,j--;
			continue;
		}
		if(v[i].x<v[j].x)
		{
			cnt+=v[i].x;
			v[j].x-=v[i].x;
			v[i].c=0;
			i++;
			continue;
		}
		if(v[i].x>v[j].x)
		{
			cnt+=v[j].x;
			v[i].x-=v[j].x;
			v[j].c=0;
			j--;
			continue;
		}
	}
	cout << cnt;
	return 0;
}
