#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int t1,t2,t3=1;
	if(s1[2]<='B')int t1=1;
	else int t1=0;
	if(s2[2]<='B')int t2=1;
	else int t2=0;
	if(c1==c2)cout << 1;
	else{
		cout << 0;
		t3=0;
	} 
	if(s1[0]==s2[0] && s1[1]==s2[1] && t3==1)cout << 1;
	else{
		cout << 0;
		t3=0;	
	} 
	if(t1==t2 && t3==1)cout << 1;
	else{
		cout << 0;
		t3=0;
	} 
	if(abs(s1[2]-s2[2])==1 && (int)(s1[2]+s2[2])!=135 && t3==1)cout << 1;
	else cout << 0;
	return 0;
}
//02 01A 02 01B
