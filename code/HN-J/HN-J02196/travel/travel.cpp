#include <bits/stdc++.h>
using namespace std;
string sa , sb , ca , cb;
char x , y;
int main()
{
   freopen("travel.in" , "r" ,stdin);	
   freopen("travel.out" , "w" ,stdout);	
   cin >> ca >> sa >> cb >> sb;
   x = sa[2];
   y = sb[2];
    if(ca == cb) cout << 1;
   else
   {
   	cout << "0000" << endl;
   	return 0;
   }
   if((sa[0] * 10+ sa[1]) == (sb[0] * 10 + sb[1])) cout << 1;
   else
   {
   	cout << "000" << endl;
   }
   if((x == 'A' && (y == 'B' || y == 'C')) || (x == 'B' && (y == 'A' || y == 'C')) || (x == 'C' && (y == 'B' || y == 'A')) || (x == 'D' && y == 'F') || (x == 'F' && y == 'D'))
   {
   	cout << 1;
   	if((x == 'A' && y == 'B') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'B') || (x == 'D' && y == 'E') || (x == 'E' && y == 'D'))
   	{
   	    cout << 1;	
	}
	else cout << 0;
   }
   else
   {
   	 cout << "00" <<endl;
   	 return 0;
	}
   
   return 0;
} 
