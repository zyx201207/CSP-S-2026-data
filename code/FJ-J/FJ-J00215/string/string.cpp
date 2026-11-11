#include<iostream>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXNN = 1e9;
int n;
char num[MAXNN];
unsigned long long len = 0, ans = 0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		char c;
		cin >> x >> c;
		
		for(int j = 1; j <= x; j++)
		{
			num[++len] = c;
		}
	}
	for(int i = 1; i <= len / 2; i++)
	{
		if(num[i] == num[len - i + 1])
		{
			ans += 2;
		}
	}
	
	cout << (len - ans) / 2 ;
	return 0;
}
