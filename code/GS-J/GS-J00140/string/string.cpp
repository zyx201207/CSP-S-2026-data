#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cnt,l;
	long long n;
	int a[1000];
	string c,s;
	cin>>n;
	for (int i=1;i <= n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	for (int i=1;i <= c.size()*1000;i++)
	{
		s=s+int(c[i])*a[i];
	}
	for (int i=1;i <= s.size();i++)
	fclose(stdin);
	fclose(stdout);
	return 0;
}
