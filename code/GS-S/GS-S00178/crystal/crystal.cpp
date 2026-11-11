#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
int ne,cc = 1,ans = 1,ma;
long long n,m,a[N],x,y;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int m1 = m;
	if(n <= 5000)
	{
		for(int i = 1;i <= n;i++ ) cin>>a[i];
		sort(a + 1,a + 1 + n);
		for(int i = 1;i <= n;i++ )
		{
			ans = 1;
			m1 = m;
			for(int j = i - 1;j >= 1;j-- )
			{
				if( m1 >= a[i] - a[j] )
				{
					ans++;
					m1 -= (a[i] - a[j]);
				}
				else
				{
					ma = max(ma,ans);
					ans = 1;
					break;
				}
			}
			ma = max(ma,ans);
		}
		cout<<ma;
	}
	else
	{
		for(int i = 1;i <= n;i++ ) cin>>a[i];
		int cha = a[2] - a[1];
		while(1)
		{
			if(m1 >= (cha * cc * (cc + 1) / 2) && cc < n)
			{
				cc++;
			}
			else
			{
				cout<<cc;
				return 0;
			}
		}
	}
	return 0;
}
