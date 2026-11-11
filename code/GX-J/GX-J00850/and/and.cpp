#include <iostream>
#include <cstdio>
using namespace std;

const long long MAXN = 2e10;
long long a[2e10 + 5];
long long n, m;

int erjinzhi(int num)
{
	int quanzhi = 0;
	int sum = 0;
	int dangqian = num % 10;
	while (1)
	{
		sum += dangqian * (2 ^ quanzhi);
		num / 10;
		quanzhi++;
		if (num < 1)
		{
			break;
		}
	} 
	return sum;
}

int yu(int n1, int n2)
{
	int sum1 = erjinzhi(n1);
	int sum2 = erjinzhi(n2);
	
	int dangqian1 = sum1 % 10;
	int dangqian2 = sum2 % 10;
	
	int jieguo = 0;
	while (1)
	{
		jieguo += (dangqian1 and dangqian2);
		
		dangqian1 / 10;
		dangqian2 / 10;
		
		if (dangqian1 < 0 || dangqian2 < 0)
		{
			return false;
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	
	return 0;
}
