#include <bits/stdc++.h>
using namespace std;

int a[200010];
int b[200010];
int main()
{
	//cout << (31 & 15 & 7)<< endl;
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	int maxn[200009] = {0};
	int we = 0;
	for(int i = 200010;i >= 0;i--)
	{
		if(b[i]!=0)
		{
			for(int j = 0;j < b[i];j++)
			{
				maxn[we]=i;
				we++;
				if(we==m)
				{
					break;
				}
			}
		}
	}
	cout << maxn[m-1];
	return 0;
}
