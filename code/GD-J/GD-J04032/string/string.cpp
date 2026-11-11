#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;
	vector<char> b(n);
	vector<long long> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i] >> b[i];
	long long la,ra,ans=0;
	long long l=0,r=n-1;
	char lb,rb;
	la=a[l];ra=a[r];
	lb=b[l];rb=b[r];
	while(l<r)
	{
		if(lb==rb)
		{
			if(la<ra)
			{
				l++;
				ra-=la;
				la=a[l];lb=b[l];
			}
			else if(la>ra)
			{
				r--;
				la-=ra;
				ra=a[r];rb=b[r];
			}
			else
			{
				l++;r--;
				la=a[l];lb=b[l];
				ra=a[r];rb=b[r];
			}
		}
		else
		{
			if(la<ra)
			{
				l++;
				ra-=la;
				ans+=la;
				la=a[l];lb=b[l];
			}
			else if(la>ra)
			{
				r--;
				la-=ra;
				ans+=ra;
				ra=a[r];rb=b[r];
			}
			else
			{
				l++;r--;
				ans+=ra;
				la=a[l];lb=b[l];
				ra=a[r];rb=b[r];
			}
		}
	}
	cout << ans;
	return 0;
}
