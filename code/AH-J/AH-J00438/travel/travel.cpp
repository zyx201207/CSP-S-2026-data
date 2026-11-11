#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2){
		cout << "1";
		int n1,n2;
		n1=(s1[0]-48)*10+s1[1]-48;
		n2=(s2[0]-48)*10+s2[1]-48;
		if (n1==n2){
			cout << "1";
			if ((s1[2]<=67&&s2[2]<=67)||(s1[2]>67&&s2[2]>67)){
				cout << "1";
				if (s1[2]-s2[2]==1||s1[2]-s2[2]==-1||s1[2]+s2[2]==138) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}  
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
