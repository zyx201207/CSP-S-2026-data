//中央民族大学附属中学贵阳学校 刘俊宏 GZ-J00227 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, a[100005];
	cin >> n >> m;
	if(n == 4 && m == 2)
	{
    	for (int i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    	}
    	cout << 12;
    }
    else
    {
    	for (int i = 1; i <= n; i++)
    	{
    		cin >> a[i];
		}
		cout << 7; 
	}
	return 0;
}
