#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int num[200005] = {};
int mx = -1;

int main()
{
	FILE* read_file = freopen("and.in", "r", stdin);
	FILE* write_file = freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if((num[i] & num[j]) > mx)
			{
				mx = num[i] & num[j];
			}
			//cout << "if:" << num[i] << "&" << num[j] << ",max=" << mx << endl;
			//cout << num[i] << "&" << num[j] << "=" << (num[i] & num[j]) << endl;
		}
	}
	cout << mx;
	return 0;
}
