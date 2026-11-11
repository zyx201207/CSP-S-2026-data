#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	//cout << s2[0] << endl << s2[1] << endl << s2[2] << endl;
	bool a=false;
	if(c1==c2){				//同一节车厢 
		cout << 1;
		a = true;
	}
	else{
		cout << 0;
	}
	bool p=false;
	if(s2[0]==s1[0] && s2[1]==s1[1] && a==true){	//同一排 
		cout << 1;
		p = true;
	}
	else{
		cout << 0;
	}
 
	bool is = false;		//同一侧 
	bool is1 = false;		//相邻 
	if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='B'&&s2[2]=='A' || s1[2]=='C'&&s2[2]=='A'|| s2[2]=='C'&&s1[2]=='A'|| s1[2]=='C'&&s2[2]=='B'|| s2[2]=='C'&&s1[2]=='B'){
		is = true;
	}
	if(s1[2]=='D'&&s2[2]=='F' || s1[2]=='F'&&s2[2]=='D'){
		is = true;
		is1 = true;
	}
	if(is==true && p==true && a==true){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='B'&&s2[2]=='A'|| s1[2]=='C'&&s2[2]=='B'|| s2[2]=='C'&&s1[2]=='B'){
		is1 = true;
	}
	if(is1 == true && is==true && p==true && a==true){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
