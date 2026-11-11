#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
long long s[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	long long sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i]>> c[i];
		sum+=a[i];	
		s[i] = s[i-1]+a[i];
	}
	long long l = 1,r=sum;
	int p =1,q=n;
	while(l<r)
	{
		long long y=r-l;
		if(c[p]!=c[q])
		{
			ans+=min(y,min(s[p]-l+1,r-s[q-1]+1));
		}
		l+=min(y,min(s[p]-l+1,r-s[q-1]+1));
		r-=min(y,min(s[p]-l+1,r-s[q-1]+1));
		if(l>s[p])p++;
		if (r == s[q-1])q--;
	}
	cout << ans;
	return 0;
}
