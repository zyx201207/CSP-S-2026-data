#include<bits/stdc++.h>
using namespace std;
string ca , sa , cb , sb , ans[7];
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> ca >> sa >> cb >> sb;
	if(ca == cb){//是否同车厢 1
		cout << "1";
		if(sa[0] == sb[0] && sa[1] == sb[1]){	//是否同排 1
			cout << "1";
			if((sa[2] < 'D' && sb[2] < 'D') || (sa[2] >= 'D') && sb[2] >= 'D'){	//是否同过道一侧 
				cout << "1";
				if(sa[2] + 1 == sb[2] || sa[2] - 1 == sb[2])
					cout << "1";//是否相邻 
				else
					cout << "0";
			}
			else{
					cout << "00";
			}
		}
		else
			cout << "000";		
	}
	else
		cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//02 01C 02 01A 1110
//02 01C 02 01D 1100
//02 02B 02 01A 1000
//02 01A 03 01A 0000
