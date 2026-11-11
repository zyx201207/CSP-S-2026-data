#include <bits/stdc++.h>
using namespace std;
unsigned long long n,a[100005],cnt,ans;
char b[100005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(unsigned long long j=cnt;j<cnt+a[i];j++)s[j]=b[i];
		cnt+=a[i];
	}
	for(unsigned long long i=0;i<cnt/2;i++)
	{
		if(s[i]!=s[cnt-i-1])ans++;
	}
	cout<<ans;
	return 0;
 } 
