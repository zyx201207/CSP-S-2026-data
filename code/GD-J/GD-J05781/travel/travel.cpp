#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	{
	ll a = int(c1[0]) - 48;		//处理车厢号 
	ll b = int(c2[0]) - 48;
	ll cR = a * 10 + int(c1[1]) - 48;
	ll cX = b * 10 + int(c2[1]) - 48;	
	if(cR == cX){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	}
	
	{
	ll a = int(s1[0]) - 48;		//处理座位号 
	ll b = int(s2[0]) - 48;
	ll sR = a * 10 + int(s1[1]) - 48;
	ll sX = b * 10 + int(s2[1]) - 48;
	char nR = s1[2],nX = s2[2];
	if(sR == sX){
		cout << 1;
		if(nR == 'F' || nR == 'D'){
			if(nX == 'F' || nR == 'D'){
				cout << "11";
			}else{
				cout << "00";
			}
		}else if(nR == 'A' || nR == 'B' || nR == 'C'){
			if(nX == 'A' || nX == 'B' || nX == 'C'){
				cout << 1;
				if(nR == 'A' && nX == 'B'){
					cout << 1;
				}else if(nR == 'B' && nX == 'A'){
					cout << 1;
				}else if(nR == 'B' && nX == 'C'){
					cout << 1;
				}else if(nR == 'C' && nX == 'B'){
					cout << 1;
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}
	}else{
		cout << "000";
	}
	}
	return 0;
}
