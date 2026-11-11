#include <bits/stdc++.h>
using namespace std;

int main()
{
	frepon("string.in","r",stdin);
	frepon("string.out","w",stdout);
	int n;
	cin >> n;
	long long b[200];
	char c[200];
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
		cin >> c[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i];j++)
		{
			n=n-1;
			cout << n << endl;
		}
	}

	return 0;	
}
