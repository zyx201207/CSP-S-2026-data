#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int num[n];
	char ch[n];
	for(int i = 0; i < n; i++)
	{
		cin >> num[i] >> ch[i];
	}
	if(n == 1)
	{
		cout << 0;
	}
	if(n == 2)
	{
		if(ch[0] == ch[1])
		{
			cout << 0;
		}
		else
		{
			if(num[0] >= num[1])
			{
				cout << num[1];
			}
			else
			{
				cout << num[0];
			}
		}
	}
	if(n == 3)
	{
		if(ch[0] == ch[1] && ch[1] == ch[2])
		{
			cout << 0;
		}
		else
		{
			if(ch[0] == ch[1])
			{
				if(num[0] + num[1] >= num[2])
				{
					cout << num[2];
				}
				else
				{
					cout << num[0] + num[1];
				}
			}
			else if(ch[0] == ch[2])
			{
				if(num[0] + num[2] >= num[1])
				{
					cout << num[1];
				}
				else
				{
					cout << num[0] + num[2];
				}
			}
			else if(ch[2] == ch[1])
			{
				if(num[2] + num[1] >= num[0])
				{
					cout << num[0];
				}
				else
				{
					cout << num[2] + num[1];
				}
			}
			else
			{
				if(num[0] + num[1] <= num[2])
				{
					cout << num[0] + num[1];
				}
				if(num[0] + num[1] > num[2])
				{
					cout << num[2];
				}
				if(num[0] + num[2] >= num[1])
				{
					cout << num[1];
				}
				if(num[0] + num[2] < num[1])
				{
					cout << num[0] + num[2];
				}
				if(num[1] + num[2] >= num[0])
				{
					cout << num[0];
				}
				if(num[1] + num[2] < num[0])
				{
					cout << num[1] + num[2];
				}
			}
		}
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
