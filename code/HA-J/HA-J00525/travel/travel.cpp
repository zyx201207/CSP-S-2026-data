#include<bits/stdc++.h>
using namespace std;

char c1[3], s1[4], c2[3], s2[4];
char ans[4] = {'1', '1', '0', '0'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel2.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < 3; i++)
	{
		if(c1[i] != c2[i]) {ans[0] = '0'; break;}
	}
	for (int i = 0; i < 2; i++)
	{
		if(s1[i] != s2[i]) {ans[1] = '0'; break;}
	}
	if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') ans[2] = '1';
	if (s1[2] >= 'E' && s1[2] <= 'F' && s2[2] >= 'E' && s2[2] <= 'F') ans[2] = '1';
	if (int(s1[2] - s2[2]) == 1 || int(s2[2] - s1[2]) == 1) ans[3] = '1';
	for (int i = 0; i < 4; i++)
	{
		cout << ans[i];
	}
	 
	
	
	return 0;
}
