#include <iostream>
#include <algorithm>
using namespace std;
long long num[500005];
long long lin[500005];
bool lin2[500005];
long long n,m,a;
int fm,l,r;
int centre;
int ji(int o)
{
	if(o == n)
	{
		return lin[centre] - lin[n];
	}
	else
	{
		return lin[centre] - lin[o] + ji(o+1);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];
		lin2[i] = true;
	}
	int cnt = 1;
	for(int i = 1; i <= n; i++)
	{
		int maxn = -999999999;
		int w = 0;
		for(int j = 1; j <= n; j++)
		{
			if(maxn < num[j] && lin2[j] == true)
			{
				maxn = num[j];
				w = j;
			}
		}
		lin[i] = maxn;
		lin2[w] = false;
	}
	l = 1;
	r = n;
	centre = (l+r)/2;
	int zuizhong;
	bool ft = false;
	while(l < r)
	{
		fm = ji(centre);
		if(fm > m)
		{
			l = centre;
		}
		else if(fm == m)
		{
			zuizhong = n - centre + 1;
			ft = true;
			break;
		}
		else
		{
			r = centre;
		}
		centre = (l + r)/2;
	}
	for(int i = centre; lin[i-1] == lin[i]; i--)
	{
		zuizhong++;
	}
	if(ft)
	{
		cout << zuizhong;
	}
	else if(ji(centre) > m)
	{
		cout << n-centre;
	}
	else
	{
		cout << n-centre+2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
