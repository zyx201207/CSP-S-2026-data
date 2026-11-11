#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+9;
struct node{
	int x;
	char op;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	long long ans=0,len = 0,cnt = 0;
	int n;
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i].x >> a[i].op;
		len += a[i].x;
	}
	int l = 1,r = n;
	while(cnt<=len/2)
	{
		if(a[l].op == a[r].op)
		{
			if(a[l].x == a[r].x)
			{
				cnt += a[l].x;
				l++,r--;
			}
			else if(a[l].x > a[r].x)
			{
				
				a[l].x -= a[r].x;
				cnt += a[r].x;
				r--;
			}
			else if(a[l].x < a[r].x)
			{
				
				a[r].x -= a[l].x;
				cnt += a[l].x;
				l++;
			}
		}
		else
		{
			if(a[l].x == a[r].x)
			{
				ans += a[l].x;
				cnt += a[l].x;
				l++,r--;
			}
			else if(a[l].x > a[r].x)
			{
				a[l].x -= a[r].x;
				ans += a[r].x;
				cnt += a[r].x;
				r--;
			}
			else if(a[l].x < a[r].x)
			{
				a[r].x -= a[l].x;
				ans += a[l].x;
				cnt += a[l].x;
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}
