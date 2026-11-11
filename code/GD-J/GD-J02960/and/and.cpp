#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	int a[200010];
	cin >> n >> m;
	cin >> a[1];
	int num = a[1];
	int biggest = 0;
	for(int i = 2;i <= n;i++)
	{
		cin >> a[i];
		num = num&a[i];
		if(a[i] >= biggest)
		{
			biggest = a[i];
		}
	}
	if(m == n)
	{
		cout << num;
		return 0;
	}
	if(m == 1)
	{
		cout << biggest;
	}
	return 0; 
}
