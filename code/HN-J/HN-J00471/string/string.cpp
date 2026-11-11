#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	frepoen("string.in","r",stdin);
	frepoen("string.out","w",stdout);
	int l;
	cin >> l;
	for(int i = 0;i < l;i++)
	{
		cin >> s[i];
	}
	int sum = 0;
	for(int i = 0;i <= l / 2;i++)
	{
		for(int j = l-1;j >= l / 2;j--)
		{
			if(s[i] != s[j])
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
