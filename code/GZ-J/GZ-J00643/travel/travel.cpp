//GZ-J00643 个人报名 周晨诚
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2,d1,d2;
	cin  >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	for(int i=0;i<3;i++){
		char a=s1[i],b=s2[i];
		if(i == 2){
			if(d1 == d2){
				cout << "1";
				int a1 = a,b1 = b;
				int z = abs(a1 - b1);
				if(z == 1 && a1 != 67 && b1 != 68){
					cout << "11";
				} else if( (a1 <= 67 && a1 >= 65) && (b1 <= 67 && b1 >= 65) ){
					cout << "10";
				} else if (z ==1 && a1 == 67 && b1 == 68) {
					cout << "00";
				} else {
					cout << "00";
				}
			} else{ 
				cout << "000";
			}
		} else {
			d1 += s1[i];
			d2 += s2[i];
		}
	}
	return 0;
} 
