#include <bits/stdc++.h>
using namespace std;
char cxa[10], cxb[10], zwa[10], zwb[10];
int main()
{
	freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", cxa, zwa, cxb, zwb);
	if (cxa[0] != cxb[0] || cxa[1] != cxb[1])
	{
		printf("0000");
		return 0;
	}
	printf("1");
	if (zwa[0] != zwb[0] || zwa[1] != zwb[1])
	{
		printf("000");
		return 0;
	}
	printf("1");
	if (!(zwa[2] >= 'D' && zwb[2] >= 'D') && !(zwa[2] <= 'C' && zwb[2] <= 'C'))
	{
		printf("00");
		return 0;
	}
	printf("1");
	if (zwa[2] + 1 != zwb[2] && zwb[2] + 1 != zwa[2])
	{
		printf("0");
		return 0;
	}
	printf("1"); 
	return 0;
}
