#include<iostream>
using namespace std;
#define int long long
const int maxn = 2e5+10;
int n,ans;

struct node
{
	int x;
	char a;
}m[maxn];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> m[i].x >> m[i].a;
	int l = 1,r = n;
	while(l<r&&l!=0&&r!=0)
	{
		if(m[l].x<m[r].x)
		{
			m[r].x = m[r].x-m[l].x;
			if(m[l].a != m[r].a) ans+=m[l].x;
			l++;
		}
		else if(m[l].x>m[r].x)
		{
			m[l].x = m[l].x-m[r].x;
			if(m[l].a != m[r].a) ans+=m[r].x;
			r--;
		}
		else
		{
			if(m[l].a != m[r].a) ans+=m[l].x;
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
