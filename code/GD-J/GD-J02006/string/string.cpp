#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n,L = 0,sum = 0;
	string S[20005];
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		int a;
		string b;
		cin >> a >> b;
		for(int j=L+1;j<=a+L;j++)
		{
			S[j] = b;
		}
		L+=a;
	}
	for(int i=1;i<=L/2;i++)
	{
		if(S[i] != S[L+1-i])
		{
			sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
