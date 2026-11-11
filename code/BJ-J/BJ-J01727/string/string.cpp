#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5+10;

struct node
{
	ll num;
	char c;
}a[N];
int cnt;
ll l = 1, r = 0,ans = 0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1; i<= n; i++)
	{
		int x;
		char ch;
		cin>>x>>ch;
		r += x;
		if(i == 1)
		{
			a[++cnt] = {x,ch};
			continue;
		}
		if(ch == a[cnt].c)
		{
			a[cnt].num += x;
		}
		else
		{
			a[++cnt] = {x,ch};
		}
	}
	int i = 1,j = cnt;
	while(l < r)
	{
		while(a[i].c == a[j].c && l < r)
		{
			if(a[i].num == a[j].num)
			{
				l += a[i].num, r -= a[i].num;
				j--, i++;
				continue;
			}
			if(a[i].num > a[j].num)
			{
				a[i].num -= a[j].num;
				l += a[j].num, r -=	a[j].num;
				j--;
			}
			else
			{
				a[j].num -= a[i].num;
				l += a[i].num, r -= a[i].num;
				i++;
			}
		}
		if(l >= r) break;
		if(a[i].num == a[j].num)
		{
			l += a[i].num, r -= a[i].num;
			ans += a[i].num;
			j--,i++;
			continue;
		}
		if(a[i].num > a[j].num)
		{
			a[i].num -= a[j].num;
			l += a[j].num, r -=	a[j].num;
			ans += a[j].num;
			j--;
		}
		else
		{
			a[j].num -= a[i].num;
			l += a[i].num, r -= a[i].num;
			ans += a[i].num;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
