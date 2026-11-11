#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int xiang1,xiang2;
	string poos1,poos2;
	cin >> xiang1 >> poos1 >> xiang2 >> poos2;
	bool yi = (xiang1 == xiang2);
	bool er = yi && (poos1[0] == poos2[0] && poos1[1] == poos2[1]);
	bool sann = yi && er && (poos1[2] <= 'C' && poos2[2] <= 'C' || poos1[2] > 'C' && poos2[2] > 'C');
	bool si = 0;
	if (yi && er && sann)
	{
		int cha = abs(poos1[2] - poos2[2]);
		if (cha == 1 || (poos1[2] == 'D' && poos2[2] == 'F') || (poos1[2] == 'F' && poos2[2] == 'D')) si = 1;
	}
	cout << yi << er << sann << si;
	
	return 0;
}
