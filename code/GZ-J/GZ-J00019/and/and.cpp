//GZ-J00019 µËÔÆÐù
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int ma=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n==m)
	{
		ma=a[1];
		for(int i=2;i<=n;i++)
		{
			ma&=a[i];
		}
		cout << ma;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long k;
		for(int j=i+1;j<i+m;j++)
		{
			k=a[j-1];
			k&=a[j];
		}
		ma=(ma>k ? ma:k);
	}
	cout << ma;
	return 0;
}
