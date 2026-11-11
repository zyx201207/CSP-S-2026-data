#include <bits/stdc++.h>
using namespace std;

long long a[200005]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cout << 3 and 15;
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	long long num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long cnt=and(a[i],a[j]);
			if(cnt>=num)
			{
				num=cnt; 
			}
		}
	}
	cout << num;
	return 0;
}
