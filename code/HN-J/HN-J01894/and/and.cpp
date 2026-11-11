#include <bits/stdc++.h>
using namespace std;
long long n,a[15],m,num=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j<=1;j--)
		{
			if((a[i]&a[j])>num)
			{
				num=a[i]&a[j];
			}
		}
	}
	cout << num;
}
