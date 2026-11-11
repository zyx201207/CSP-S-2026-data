#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[3],b[3],a1[4],b1[4];
	cin >> a >> a1 >> b >> b1;
	if (a[0]==b[0]&&a[1]==b[1])cout << 1;	
	else
	{
		cout << "0000";
		return 0;
	}
	if (a1[0]==b1[0]&&a1[1]==b1[1])cout << 1;
	else
	{
		cout << "000";
		return 0;
	}	
	if (('A'<=a1[2] && a1[2]<='C' &&'A'<=b1[2] && b1[2]<='C')||('D'<=a1[2] && a1[2]<='F' &&'D'<=b1[2] && b1[3]<='F'))cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	if ((a1[2]+1==b1[2])||(a1[2]-1==b1[2])||(a1[2]=='D'&&b1[2]=='F')||(a1[2]=='F'&&b1[2]=='D'))cout << 1;	
	else cout << 0;
	return 0;
	fclose(stdin);
	fclose(stdout);	
} 
