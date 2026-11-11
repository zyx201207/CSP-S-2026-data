#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200010],ans[200010];
string er[200010], an[200010];
string toer(int x)
{
	string s="", s1="";
	while (x)
	{
		s+=(x%2)+'0';
		x/=2;
	}
	for (int i=s.size()-1;i>=0;i--)
	{
		s1+=s[i];
	}
	return s1;
}
string anweiyu(string s1, string s2)
{
	string s3="";
	int len1=s1.size();
	int len2=s2.size();
	if (len1>len2) swap(s1, s2);
	for (int i=0;i<len1;i++)
	{
		if (s1[i] == s2[i]) s3+=s1[i];
		else s3+='0';
	}
	return s3;
}
int toshi(string s1)
{
	int shi=0;
	for (int i=s1.size()-1;i>=0;i--)
	{
		shi+=(s1[i]-'0')*int (pow(2,(6-i)));
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1;i<=n;i++)
	{
		er[i] = toer(a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			an[i] = anweiyu(er[i], er[j]);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ans[i]=toshi(an[i]);
		ans = max(ans, ans[i]);
	}
	cout << ans;

	return 0;
}
