#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string op = "";
unsigned long long cnt = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	unsigned long long n,a;
	char c;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for(int j = 1; j <= a; j++)
		{
			cnt++;
			op[cnt] = c;
		}
	}
	unsigned long long sum = 0;
	for(int i = 1; i <= cnt/2; i++)
	{
		if(op[i] != op[cnt+1-i])
		{
			sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
