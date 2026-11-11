#include <bits/stdc++.h>
using namespace std;

char input[200010];

int main()
{
	long long a1;
	cin >> a1;
	string a;
	for(long long i = 1;i <= a1;i++)
	{
		long long incnt;
		cin >> incnt;
		cin >> input; 
		for(long long i = 0;i < incnt;i++)
		{
			a+=input;
		}
	}
	//cout << a;
	long long cnt = 0;
	if(a1==1)
	{
		cout << 0;
		return 0;
	}
	for(long long j = 1;j <= a.size()/2;j++)
	{
		//if(a.size()%2==0)
		//{
			if(a[j-1]!=a[a.size()-j])
			{
				cnt++;
				continue;
			}
		//}
	}
	cout << cnt;
 } 
