#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],cnt;
char c[N];
void solve2()
{
	for (int i=1;i<=n/2+n%2;i++)
		if (c[i]!=c[n-i+1])
			cnt=cnt+max(a[i],a[n-i+1]);
	cout<<cnt;
}
void solve1()
{
	string s=" ";
	for (int i=1;i<=n;i++)
		for (int j=1;j<=a[i];j++)
			s+=c[i];
	int len=s.size()-1;
	for (int i=1;i<=len/2;i++)
		if (s[i]!=s[len-i+1]) cnt++;
	cout<<cnt;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int maxn=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		maxn=max(maxn,a[i]);
	}
	if (maxn*n>10000000) solve2();
	else solve1();
	return 0;
 } 
