#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,a[MAXN];
char c[MAXN];
long long sum,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		while(a[i]--) s=s+c[i];
	}
	for(long long i1=0;i1<(sum+1)/2;i1++)
	{
		ans+=(s[i1]!=s[sum-1-i1]);
	}
	cout << ans;
	return 0;
} 
