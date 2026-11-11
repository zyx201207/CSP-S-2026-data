#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n];
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int t = 0;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
            if(a[i] < a[i+1])
		    {
                t = a[i+1];
		    	a[i+1] = a[i];
		    	a[i] = t;
		    }
		}
	}
	ans = a[0];
	for(int i = 1;i < m;i++)
	{
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
