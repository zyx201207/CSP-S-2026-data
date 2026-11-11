#include<bits/stdc++.h>
using namespace std;
int a[2000005];
char c[2000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	long long n;
	cin>>n;
	string s = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s = s+c[i];
		}
	}
	cout<<s;
	return 0;
}
