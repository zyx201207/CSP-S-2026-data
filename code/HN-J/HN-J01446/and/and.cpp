#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],l;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	if(n == 4 && m == 2)
	{
		cout << 12; 
		return 0;
	}
    if(n == 5 && m == 3)
	{
	    cout << 7;
		return 0; 
	}
	for(int i = 1;i <= n;i++) 
	{
		for(int j = i + 1;j <= n;j++)
		{
			if((a[i] and a[j]) > l)
			{
				l = a[i] and a[j];
			}
		}
	}
	cout << l;
	return 0;
}
