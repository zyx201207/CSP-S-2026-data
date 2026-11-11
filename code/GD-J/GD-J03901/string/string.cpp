#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], b[200005], c[200005], jsq, sum, ol, k, h, ans, l, r, ss;
bool pd;
char t[200005], tb[200005], tc[200005];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] >> t[i];
		jsq+=a[i];
	}
	ss=jsq;
	jsq=jsq/2;
	for (int i=1; i<=n; i++)
	{
		if (!pd)
		{
			sum=ol;
			sum+=a[i];
			if (sum>jsq)
			{
				if (jsq-ol>0)
				{
					k++;
					b[k]=jsq-ol;
					tb[k]=t[i];
				}
				if (ss%2)
				{
					a[i]=a[i]-jsq+ol-1;
				}
				else
				{
					a[i]=a[i]-jsq+ol;
				}
				pd=1;
				if (a[i])
				{
					h++;
					c[h]=a[i];
					tc[h]=t[i];
				}
				continue;
			}
			k++;
			b[k]=a[i];
			tb[k]=t[i];
			ol=sum;
		}
		else
		{
			h++;
			c[h]=a[i];
			tc[h]=t[i];
		}
	}
	for (int i=1, j=h; i<=k && j>=1;)
	{
		if (tb[i]!=tc[j])
		{
			ans+=min(b[i]-l, c[j]-r);
		}
		if (b[i]-l<c[j]-r)
		{
			r+=b[i]-l;
			l=0;
			i++;
		}
		else if (c[j]-r<b[i]-l)
		{
			l+=c[j]-r;
			r=0;
			j--;
		}
		else
		{
			l=0;
			r=0;
			j--;
			i++;
		}
	}
	cout << ans;
	return 0;
}
