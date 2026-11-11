#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans = 0,y,z;
	long long a[100005];
	cin >> n >> m;
	for(int i=0 ; i<=n ; i++)
	{
		cin >> a[i];
	}
	for(int i=1 ; i<=n ; i++)
	{
		z = z + i;
	}
	for(int i=0 ; i<z ;i++)
	{
		for(int j=0 ; j<z ; j++)
		{
			y=a[i] and a[j];
			if(y>ans)
			{
				ans = y;
			}
		}
	}
	cout << ans;
    return 0;
}

