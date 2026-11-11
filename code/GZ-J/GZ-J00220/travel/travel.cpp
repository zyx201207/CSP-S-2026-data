//GZ-J00220	  遵义市南白初级中学   吴濬嘉 
#include <bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	x = sr.substr(0,2);
	y = sx.substr(0,2);
	char a = sr[2],b = sx[2]; 
	if (cr == cx)	cout << "1";
	else{
		cout << "0000";
		return 0;
	}	
	if (x == y) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	if ((a >='A'&& a <='C'&& b >= 'A' && b <= 'C')||(a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F'))
		cout << "1";
	else{
		cout << "00";
		return 0;
	}
	if (a + 1 == b)	cout << "1";
	else cout << "0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

