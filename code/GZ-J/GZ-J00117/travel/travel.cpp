//GZ-J00117 张梓珈 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string t1,s1,t2,s2;cin>>t1>>s1>>t2>>s2;
	if(t1 == t2)cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	char x = s1[2];char y = s2[2];
	string w = s1.substr(0,2);string e = s2.substr(0,2);
	
	if(w == e)cout << 1;
	else {
		cout << 0 << 0 << 0;
		return 0;
	}
	
	if((x == 'A' && y == 'B') || (x == 'B' && y == 'A'))cout << 1 << 1;
	else if((x == 'B' && y == 'C') || (x == 'C' && y == 'B'))cout << 1 << 1;
	else if((x == 'E' && y == 'D') || (x == 'D' && y == 'F'))cout << 1 << 1;
	else if((x == 'A' && y == 'C') || (x == 'C' && y == 'A'))cout << 1 << 0;
	else cout << 0 << 0;
	
	return 0;
}
