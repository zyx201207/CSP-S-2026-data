#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string ar, br, ax, bx;
	cin >> ar >> br >> ax >> bx;
	
	bool ansa, ansb, ansc, ansd;
	
	ansa = ar == ax;
	ansb = ansa && (br[0] == bx[0]) && (br[1] == bx[1]);
	
	if (ansb)
	{
		if ((bx[2] == 'A' || bx[2] == 'B' || bx[2] == 'C') &&
		    (br[2] == 'A' || br[2] == 'B' || br[2] == 'C'))
		    ansc = 1;
		else if ((bx[2] == 'D' || bx[2] == 'F') && (br[2] == 'D' || br[2] == 'F'))
			ansc = 1;
		else ansc = 0;
	}
	else ansc = 0;
	
	if (ansc)
	{
		if (
			(bx[2] == 'A' && br[2] == 'B') || (bx[2] == 'B' && br[2] == 'A') ||
			(bx[2] == 'B' && br[2] == 'C') || (bx[2] == 'C' && br[2] == 'B') ||
			(bx[2] == 'D' && br[2] == 'F') || (bx[2] == 'F' && br[2] == 'D') 
		)
			ansd = 1;
		else ansd = 0;
	}
	else ansd = 0;
	
	cout << ansa << ansb << ansc << ansd << endl;
	
	return 0;
} 
