#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
const int INF = 0x3f3f3f3f;

int n , m ,ans;
pair<int,int> a[N];

int popc(int x)
{
	int ans=0;
	while(x)
	{
		x = x & (x-1);
	}
	return ans;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		int tmp;
		cin >> tmp;
		a[i] = make_pair(popc(tmp) , tmp);
	}
	sort(a+1,a+n+1,greater< pair<int,int> >());
	
	ans = a[1].second;
	for(int i = 2;i <= m;i++)
	{
		ans = ans & a[i].second;
	}
	cout << ans;
	return 0;	
} 
