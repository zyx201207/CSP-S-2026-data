#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);                         
	int n,m,q=0;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	if(m == 1)
	{
		for(int i=0;i<n;i++)
		{
			q = max(q,a[i]);
		}
		cout << q;
	}
	bool v = false;
	if(m == 2)
	{
		for(int i=0;i<n;i++)
		{
			for(int o=0;o<i;o++)
			{
				if(a[i] == a[o])
				{
					v = true;
					break;
				}
			}
			if(v)
			{
				cout << a[i];
				break;
			}
		}
	}
	return 0;
}
