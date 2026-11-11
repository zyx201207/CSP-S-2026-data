#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in", "r", stdin);
freopen("travel.out", "w", stdout);
string s1, s2, s3, s4; cin >> s1 >> s2;
cin >> s3 >> s4;
bool z = 1;
if(s1 == s3){
cout << 1;
} 
else{
cout << 0;
z = 0;
}
string ss = "";
ss += s2[0]; ss += s2[1];
string s1s1 = "";
s1s1 += s4[0]; s1s1 += s4[1];
if((s1s1 == ss) && (z == 1){
cout << 1;
} 
else{
cout << 0;
z = 0;
} 
if((s2[2] <= 'C' && s4[2] <= 'C' || s2[2] >= 'D' && s4[2] >= 'D') && (z == 1)){
cout << 1;
}
else{
cout << 0;
z = 0;
}
if((s2[2] - s4[2] == 1 || s4[2] - s2[2] == 1) && (z == 1)){
cout << 1;
}
else{
cout << 0;
} 
return 0;
}
	
