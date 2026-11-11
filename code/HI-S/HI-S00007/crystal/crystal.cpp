#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100000005];
long long b[100000005];
long long sum,cnt,t,k = 1,d;
int sl = 1;
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	} 
	sort(a+1,a+n+1); 
	for (long long i = 1;i <= n;i++)
	{
		if (a[i] == i)
		{
			cnt++;
		}
	} 
	for (long long i = n;i >= 2;i--)
	{ 
	    t = m;
		while(t)
		{
			if (a[i]-a[i-k] <= t)
			{  
				sl++;
				t = t - (a[i]-a[i-k]);
				k++;
			}
			else if(a[i]-a[i-k] > t)
			{
				break;
			}
		}
		b[d] = sl;
		d++;
		sl = 1;
		k = 1;
    }
    sort(b+1,b+n+1);
    int ll = b[d];
    cout << ll;
	return 0;
}





