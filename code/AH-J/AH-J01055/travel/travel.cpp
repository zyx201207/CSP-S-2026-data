#include<bits/stdc++.h>
using namespace std;

string c2,s2;
int c1, s1;bool f1, f2, f3;
bool a, b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c1 >> c2 >> s1 >> s2;
	if(c2[2] == 'F' || c2[2] == 'D') a = 1;
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') b = 1;
//
	if(c1 == s1){
		cout << "1";
	}
	else{
		f3 = 1;
		cout << 0;
	} 
	 
	//
	int t1 = (c2[0]-'0')*10 + c2[1]-'0';
	int t2 = (s2[0] -'0')*10 + s2[1]-'0';
	if(t1 == t2 && !f3){
		cout << 1;
	}
	else{
		cout << 0;
		f1 = 1;
	} 
	//
	 if(!f1 && a != b && !f3){
	 	cout << 1;
	 }
	 else{
	 	cout << 0;
	 	f2 = 1;
	 } 
	 //
	 int x, y;
	 x = c2[2] - '0';
	 y = s2[2] - '0';
	 if(abs(x-y) == 1 && !f2 && !f3) cout << 1;
	 else{
	 	cout << 0;
	 } 
	return 0;
}
