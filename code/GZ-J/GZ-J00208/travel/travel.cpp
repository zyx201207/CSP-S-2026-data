//GZ-J00208 兴义市弘毅中学 廖颢云 
#include <bits/stdc++.h>
using namespace std;
string cx1,cx2,po1,po2, h1,h2;
int hang1,hang2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cx1 >> po1 >> cx2 >> po2;
	c1 = po1[2],c2 = po2[2];
	h1 = po1[0] + po1[1],h2 = po2[0] + po2[1];
	if(cx1 != cx2){
		cout << "0000";
		return 0;
	}else{
		cout << '1';
		if(h1 == h2){
			cout << '1';
			if(c1 > 'C' && c2 > 'C' || c1 <= 'C' && c2 <= 'C'){
				cout << '1';
				if(c1 + 1 == c2 || c1 - 1 == c2){
					cout << '1';
				}else{
					cout << '0';
					return 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}
	return 0;
}
