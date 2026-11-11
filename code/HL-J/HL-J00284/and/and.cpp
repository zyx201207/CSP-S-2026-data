#include <bits/stdc++.h>
using namespace std;
string s[200005],ss[200005],cc[200005];
int n,m,a[200005];
void two(int p)
{
	int x=0;
	while(p>0)
	{
		s[x]=n%2;
		p/=2;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		two(a[i]);
	}
	if (m==1)
	{
		sort(a,a+n);
		cout <<a[n-1];
	}
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			
		}
	}	
	return 0;
}
