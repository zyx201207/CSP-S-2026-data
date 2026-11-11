#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int a1=0, a2=0, a3=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		a1=1;
	}
	else{
		cout << "0";
	}
	if((s1[1]==s2[1]&&s1[0]==s2[0]) && a1==1){
		cout << "1";
		a2=1;
	}
	else{
		cout << "0";
	}if((s1[2]=='A' or s1[2]=='B'or s1[2]=='C'&&s2[2]=='A' or s2[2]=='B'or s2[2]=='C')&&a1==1&&a2==1){
		cout << "1";
		a3=1;
	}else if((s1[2]=='D' or s1[2]=='F')&&a1==1&&a2==1){
		cout << "1";
		a3=1;
	}else{
		cout << "0";
	}
	if((s1[2]=='D' or s1[2]=='F')&&a1==1&&a2==1&&a3==1){
		cout << "1";
	}
	else if(((s1[2]=='A' && s2[2]=='B')or (s1[2]=='B'&&s2[2]=='A') or (s1[2]=='B'&& s2[2]=='C')or(s1[2]=='C'&& s2[2]=='B'))&&a1==1&&a2==1&&a3==1){
		cout << "1";
	}else{
		cout << "0";
	}
	
	return 0;
}

