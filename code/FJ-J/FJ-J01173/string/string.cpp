#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
ULL a[200200],ans;
char c[200200];
bool check(string s)
{
	for (int i=0,j=(ULL)s.size()-1;i<(ULL)s.size();i++,j--)
		if (s[i]!=s[j])
			return false;
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	string s;
	for (int i=1;i<=n;i++)
	{
		scanf("%llu",&a[i]);
		scanf("%s",c);
		for (ULL j=1;j<=a[i];j++) s+=c;
	}
	if (n==1 || check(s))
	{
		printf("0");
		return 0;
	}
	for (ULL i=1,j=(ULL)s.size();i<=(ULL)s.size();i++,j--)
	{
		if (i==j) break;
		if (!check(s))
		{
			ans++;
			a[j]=a[i];	
		}
		if (j-i==1) break;
	}
	printf("%llu",ans);
	return 0;
}
