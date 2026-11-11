//GZ-J00314   陈彧山 	遵义市新蒲新区滨湖中学 
#include <bits/stdc++.h>
using namespace std;
string cx1,cx2,zw1,zw2;
long long c1,c2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>cx1 >>zw1 >>cx2 >> zw2;
	if(cx1[0] == '0'){
		c1 = cx1[1] - '0';
	}else{
		c1 = (cx1[0]-'0')*10+cx1[1] - '0';
	}
	if(cx2[0] == '0'){
		c2 = cx2[1] - '0';
	}else{
		c2 = (cx2[0]-'0')*10+cx2[1] - '0';
	}
	if(c1 == c2){
		cout <<'1';
	}else{
		cout << "0000";
		return 0;
	}
	if(zw1[0] == zw1[0] && zw1[1] == zw1[1]){
		cout << '1';
	}else{
		cout << "000";
		return 0;
	}
	if((zw1[2] <= 'C' && zw2[2] <= 'C') || zw1[2] > 'C' && zw2[2] > 'C'){
		cout << '1';
	}else{
		cout << "00";
		return 0;
	}
	if(abs(zw1[2] - zw2[2]) <= 1){
		cout << '1';
	}else{
		cout << '0';
	}
	return 0;
}

