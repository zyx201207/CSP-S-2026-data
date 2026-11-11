#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,a1,a2;
	string s1,s2;
	int a[5];
	for(int i = 1;i <= 4;i++)
		a[i] = 0; 
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(s1[1] = s2[1] && s1[0] == s2[0]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}if(s2[2] - s1[2] == 1 or s1[2] - s2[2] == 1){
		cout << "11";
	}else cout << "00";
	return 0;
}
