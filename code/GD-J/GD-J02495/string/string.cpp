/*#include <bits/stdc++.h>
using namespace std;

long long n,cnt,aaa;
long long a[200005];
long long sum[200005];
long long um[200005];
char c[200005];
int minn = 1e9;
int maxn = -1e9;
int mi,ma;
bool mii = 1,maa = 1;
long long x,y;

int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 0;i < n;i++)
	{
		cin >> a[i] >> c[i];
		aaa += a[i];
	}
	um[0] = c[0];
	for(long long i = 0;i < n;i++)
	{
		if(c[i] == um[cnt])
		{
			sum[cnt] += a[i];
		}
		else
		{
			cnt++;
			um[cnt] = c[0];
			sum[cnt] += a[i];
		}
	}
	for(long long i = 0;i < n;i++)
	{
		if(sum[i] < minn)
		{
			minn = sum[i];
			mi = i;
		}
		if(sum[i] > maxn)
		{
			maxn = sum[i];
			ma = i;
		}
	}
	for(long long i = 0;i < n;i++)
	{
		if(i == mi) mii = 1;
		else if(sum[i] % 2 != 0)
		{
			mii = 0;
			break;
		}
	}
	for(long long i = 0;i < n;i++)
	{
		if(i == ma) maa = 1;
		else if(sum[i] % 2 != 0)
		{
			maa = 0;
			break;
		}
	}
	
	if(mii && maa)
	{
		x = aaa - sum[mi];
		y = aaa - sum[ma];
		cout << min(x,y);
	}
	else
	{
		if(!mii)
		{
			if(sum[mi] % 2 == 0) x = aaa - sum[mi];
		}
		if(!maa)
		{
			if(sum[ma] % 2 == 0) x = aaa - sum[ma];
		}
		if(x == 0) cout << y;
		else if(y == 0) cout << x;
		else cout << min(x,y);
	}
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

long long n,cnt;
long long a[200005];
long long sum;
char c[200005];
bool x = 1;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 0;i < n;i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	
	long long s = c[0];
	for(long long i = 0;i < n;i++)
	{
		if(c[i] != s)
		{
			x = 0;
			break;
		}
		s = c[i];
	}//如果x==1 cout 0就好了 
	if(x) cout << 0;
	else cout << floor(sum / 2);
	
	return 0;
}
