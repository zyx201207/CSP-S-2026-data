#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool ans[4];
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string sX, sR;
	int cX, cR;
	
	
	cin>>cR>>sR>>cX>>sX;
	
	if (cR == cX){
		ans[0] = 1;
		string r = "", s = "";
		for(int i = 0; i < 2; i++){
			r += sR[i];
			s += sX[i];
		}
		if (r == s){
			ans[1] = 1;
			char r_2 = sR[2], s_2 = sX[2];
			if (('A' <= r_2 && r_2 <= 'C') && ('A' <= s_2 && s_2 <= 'C')){
				ans[2] = 1;
				if (abs(int(r_2) - int(s_2)) == 1) ans[3] = 1;	
			}
			else if (('D' <= r_2 && r_2 <= 'F') && ('D' <= s_2 && s_2 <= 'F')){
				ans[2] = 1;
				ans[3] = 1;
			}
		}
	}
	
	for(int i=0;i<4;i++) cout << ans[i];
	cout<<"\n";
	return 0;
}