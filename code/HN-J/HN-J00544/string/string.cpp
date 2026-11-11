#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long cnt;
	char z;
}a[214514];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i].cnt >> a[i].z;
	}
	int i,j;
	i = 1;
	j = n;
	long long sum = 0;
	while(i <= j)
	{
		long long minn = min(a[i].cnt,a[j].cnt);
		if(a[i].z != a[j].z)
		{
			sum += minn;
		}
		a[i].cnt -= minn;
		if(!a[i].cnt)i ++;
		a[j].cnt -= minn;
		if(!a[j].cnt)j --;
	}
	cout << sum;
	return 0;
}

