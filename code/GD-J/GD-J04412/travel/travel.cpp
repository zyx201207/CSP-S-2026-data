#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
#define RFor(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
int c[5];
int p[5];
char s[5];
int mar = 1;
int main()
{
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
	For(i, 1, 2)
		scanf("%d%d%c",&c[i], &p[i], &s[i]);
	mar &= (c[1] == c[2]);
	printf("%d",mar);
	
	mar &= (p[1] == p[2]);
	printf("%d",mar);
	
	mar &= ((s[1] <= 'C') == (s[2] <= 'C'));
	printf("%d",mar);
	
	mar &= (abs(s[1]-s[2]) == 1);
	printf("%d",mar);
	return 0;
}
//	For(i, 1, 2)
//		printf("%d%d%c",c[i], p[i], s[i]);
