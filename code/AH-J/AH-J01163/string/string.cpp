#include<bits/stdc++.h>
using namespace std;
long long n;
const int N = 2e5 + 5;
struct node
{
	long long num;
	char k;
}a[N],c[N];
long long sum[N];
long long s,e;
long long ans;
long long sumf[N],sump[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i = 1;i <= n;i++)
	{
		cin>>a[i].num>>a[i].k;
		if(a[i].k == a[i - 1].k)
		{
			a[i - 1].num += a[i].num;
			sum[i - 1] += a[i].num;
			i--;
			n--;
		c[i].num = a[i].num;
		c[i].k = a[i].k;
			continue;
		}
		c[i].num = a[i].num;
		c[i].k = a[i].k;
		sum[i] = sum[i - 1] + a[i].num;
	}
	long long d = (sum[n] + 1) / 2;
	long long l = 0,r = n;
	while(l < r)
	{
		long long mid = l + (r - l) / 2;
		if(sum[mid] >= d)
		{
			r = mid;
		}else{
			l = mid + 1;
		}
	}
//	cout<<d<<sum[r]<<r;
	s = 0;
	e = n;
	if(sum[n] % 2 == 0)
	{
		a[r].num = a[r].num - (sum[r] - d);
		c[r].num = sum[r] - d;
	}else{
		a[r].num = a[r].num - (sum[r] - d) - 1;
		c[r].num = sum[r] - d;
	}
	long long ps,pe;
	char cs,ce;
		cs = a[s].k;
		ce = c[e].k;
		ps = a[s].num;
		pe = c[e].num;
	while(s <= r && e >= r)
	{
		if(cs == ce)
		{
			if(ps >= pe)
			{
				ps -= pe;
				pe = 0;
				e--;
				ce = c[e].k;
				pe = c[e].num;
			}else{
				pe -= ps;
				ps = 0;
				s++;
				cs = a[s].k;
				ps = a[s].num;
			}
		}else{
			
			if(ps >= pe)
			{
				ans += pe;
				ps -= pe;
				pe = 0;
				e--;
				ce = c[e].k;
				pe = c[e].num;
			}else{
				ans += ps;
				pe -= ps;
				ps = 0;
				s++;
				cs = a[s].k;
				ps = a[s].num;
			}
		}
	}
	cout<<ans; 
	return 0;
}
