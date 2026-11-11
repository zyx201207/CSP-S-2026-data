#include<bits/stdc++.h>
using namespace std;

int main(){
	
//	cout << (int)'C' + (int)'D';
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1[0] == '0')c1 = c1[1];
	if(c2[0] == '0')c2 = c2[1];
//	cout << c1 << " " << c2 << endl;
	if(c1 == c2)cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	
	string l1,l2;
	char r1,r2;
	if(s1[0] == '0')l1 = s1[1];
	else {
		l1[0] = s1[0];
		l1[1] = s1[1];
	}
	
	if(s2[0] == '0')l2 = s2[1];
	else {
		l2[0] = s2[0];
		l2[1] = s2[1];
	}
	
	r1 = s1[2];
	r2 = s2[2];
	
//	cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
	
	if(l1 == l2)cout << 1;
	else {
		cout << "000";
		return 0;
	}
	
	int sum = (int)r1 + (int)r2;
	int cha = max((int)r1,(int)r2) - min((int)r1,(int)r2);
	
	if(sum == 138 || sum <= 133)cout << 1;
	else{
		cout << "00";
		return 0;
	} 
	
	if(cha == 1 && sum != 135)cout << 1;
	else cout << 0;
	
	return 0;
	
}
