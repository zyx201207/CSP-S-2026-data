#include<bits/stdc++.h>
using namespace std;
char lift[3] = {'A','B','C'};
bool record[3];
int main(){
	//准考证号:GZ-J00249 姓名:王锴碹
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << "1";
	if(s1[0] != s1[0] || s1[1] != s2[1]){
		cout << "000";
		return 0;
	}
	cout << "1";
	int cnt = 0;
	for(int i = 0;i < 3;i++){
		if(s1[2] == lift[i]) cnt++;
		if(s2[2] == lift[i]) cnt++;
	}
	if(cnt != 2 && cnt != 0){
		cout << "00";
		return 0;
	}
	cout << "1";
	for(int i = 0;i < 3;i++){
		if(s1[2] == lift[i]) record[i] = 1;
		if(s2[2] == lift[i]) record[i] = 1;		
	}
	if(record[0] && record[2]){
		cout << 0;
		return 0;
	}
	cout << "1";
	return 0; 
}

