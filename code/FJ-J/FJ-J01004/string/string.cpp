#include <bits/stdc++.h>
using namespace std;
bool cmp (int x,int y)
{
	return x<y;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long m=0;
	long long a[100000];
	string b[100000];
	cin >> n;
	for(int i=0;i<=n-1;i++)
	{
		cin >> a[i] >> b[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		if(b[i]!=b[n-i])
		{
			b[n-i]=b[i];
			m+=a[i];
		}
	}
	cout << m;
	return 0;
}
