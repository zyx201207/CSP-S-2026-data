#include<bits/stdc++.h>
using namespace std;
long long n, a[200005],cnt;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	} 
	int l = 1, r = n;
	if(n == 0 || n == 1)
	{
		cout << 0;
		return 0;
	}
	while(l < r )
	{
		if(b[l] == b[r])
		{
			if(a[l] == a[r])
			{
				l++, r--;
			}
			else if(a[l] < a[r])
			{
				a[r] = a[r] - a[l];
				l++;
			}
			else
			{
				a[l] = a[l] - a[r];
				r--;
			}
		}
		else
		{
			if(a[l] == a[r])
			{
				cnt += a[l];
				l++, r--;
			}
			else if(a[l] < a[r])
			{
				cnt += a[l];
				a[r] = a[r] - a[l];
				l++;
			}
			else
			{
				cnt += a[r];
				a[l] = a[l] - a[r];
				r--;
			}
		}
	}
	cout << cnt;
	return 0;
 } 
