#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b;
long long cnt,mx=0;
bool cmp(int x,int y) {return x>y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	b = a[1];
	if(m==1)
	{
		sort(a+1,a+1+n,cmp);
		cout << a[1];
	}
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			cnt = b & a[i];
			b = cnt;
		}
		cout << cnt;
	}
	if(m==2)
	{
		sort(a+1,a+1+n,cmp);
		cnt = a[1] & a[2];
		cout << cnt;
	}
	return 0;
}
