#include <bits/stdc++.h>

using namespace std;

char a[10][10];
bool b[100];

int main ()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	scanf ("%s %s %s %s",a[1] + 1,a[2] + 1,a[3] + 1,a[4] + 1);
	if (a[1][1] == a[3][1] && a[1][2] == a[3][2]) 
	{
		printf ("1");
		b[1] = 1;
	}
	else printf ("0");
	///////////////////////////////////////
	if (b[1] == 1 && a[2][1] == a[4][1] && a[2][2] == a[4][2]) 
	{
		printf ("1");
		b[2] = 1;
	}
	else printf ("0");
	//////////////////////////////////////
	if (b[2] == 1) 
	{
		if ((a[2][3] <= 'C' && a[4][3] >= 'D') || (a[4][3] <= 'C' && a[2][3] >= 'D')) printf ("0");
		else 
		{
			printf ("1");
			b[3] = 1;
		}
	}
	else printf ("0");
	/////////////////////////////////////
	if (b[3] == 1 && (a[2][3] - a[4][3] == 1 || a[2][3] - a[4][3] == -1)) printf ("1");
	else printf ("0");
	return 0;
}
