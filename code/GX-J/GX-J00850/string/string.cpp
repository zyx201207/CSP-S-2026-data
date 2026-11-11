#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;
int n;
int a[MAXN];
string c[MAXN];

bool samenum()
{
	bool same = true;
	for (int i = 0;i < n;i++)
	{
		if (same)
		{
			if (a[i] == a[i + 1])
			{
				continue;
			}
			else
			{
				same = false;
				return false;
			}
		}
	}
	return true;
}

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i] >> c[i];
	}
	if (samenum())
	{
		cout << "0" << endl;
		return 0;
	}
	
	return 0;
}
