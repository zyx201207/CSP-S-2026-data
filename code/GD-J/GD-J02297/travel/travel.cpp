#include<bits/stdc++.h>
using namespace std;

bool b[4];
int c1,c2;
string s1,s2;
string l1,l2;
int seat1,seat2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	l1 += s1[0];
	l1 += s1[1];
	l2 += s2[0];
	l2 += s2[1];
	seat1 = s1[2] - 'A' + 1;
	seat2 = s2[2] - 'A' + 1;
	if(seat1 > seat2) swap(seat1,seat2);
	
	if(c1 == c2) b[0] = true;
	else b[0] = false;
	if(b[0] && l1 == l2) b[1] = true;
	else b[1] = false;
	if(b[1] && ((seat1 >= 1 && seat2 <= 3) || (seat1 >= 4 && seat2 <= 6))) b[2] = true;
	else b[2] = false;
	if(b[2] && (seat2 - seat1 == 1 && seat2 != 3)) b[3] = true;
	else b[3] = false;
	
	for(int i = 0;i < 4;i++)
	{
		if(b[i]) cout << 1;
		else cout << 0;
	}
	return 0;
}
