#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) {
		cout << "1";
		string row1,row2;
		for (int i = 0;i<2;i++){
			row1 += s2[i];
			row2 += s4[i];
		}
		char c1,c2;
		c1 = s2[2];
		c2 = s4[2];
		if (row1 == row2){
			cout << "1";
			if (c1 <= 'C' && c2 <= 'C' || c1 >= 'D' && c2 >= 'D')
			{
				cout << "1";
				if (abs(c1 - c2) == 1) 
				{
					cout <<"1";
				}
				else cout << "0";
			}
			else cout <<"00";
		}
		else cout <<"000";
	}
	else cout << "0000";
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
