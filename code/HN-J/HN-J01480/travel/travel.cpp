#include <bits/stdc++.h>
using namespace std;
string t={"BABCDFD"};
string f1(string s){
	string s1=string(s[0])+string(s[1]);
	return s1;
}
bool f2(string s){
	if(s[2]=='A' || s[2]=='B' || s[2]=='C'){
		return 1;
	}else return 0;
}
bool f3(string x,string y){
	for(int i=1;i<=5;i++){
		if(x[2]==t[i]){
			return (y[2]==t[i-1] || y[2]==t[i+1]);
		}
	}
}
string seat1,seat2,id1,id2;
int main(){
	frofpen("travel.in",r,input);
	frofpen("travel.out",w,output);
	cin>>id1>>seat1>>id2>>seat2;
	bool a=(id1==id2),b=(a&&(f1(seat1)==f1(seat2))),c=(b&&(f2(seat1)==f2(seat2)))),d=(c&&);
	cout<<<<<<<<;
	return 0;
} 
