#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,N,E,sum = 1,size = 0;;
	cin >> n;
	string abc[2000000000000001];
	for(int i = 1;i <= n;i++)
	{
		cin >> N >> E;
		for(int j = 1;j <= N;i++)
		{
			abc[sum] = E;
			sum++;
		}
	}
	int len = sum / 2;
	for(int i = 1;i <= len;i++)
	{
		if(abc[i] != abc[sum])
		{
			size++;
		}
		sum--;
	}
	cout << size;
	return 0;
}
