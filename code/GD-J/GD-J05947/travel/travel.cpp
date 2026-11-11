#include<bits/stdc++.h>
using namespace std;
bool isLeft(char ch){
	if(ch=='A'||ch=='B'||ch=='C')return 1;
	return 0;
}
int getPos(char ch){
	if(ch=='A')return 1;
	if(ch=='B')return 2;
	if(ch=='C')return 3;
	if(ch=='D')return 1;
	if(ch=='F')return 2;
	return -1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool sameCar=(c1==c2);
	string row1_str=s1.substr(0,2);
	string row2_str=s2.substr(0,2);
	
	bool sameRow=sameCar&&(row1_str==row2_str);
	char ch1=s1[2];
	char ch2=s2[2];
	bool sameSide=sameRow&&(isLeft(ch1)==isLeft(ch2));
	bool adjacent=false;
	if(sameSide){
		int p1=getPos(ch1);
		int p2=getPos(ch2);
		if(abs(p1-p2)==1)adjacent=true;
	}
	cout<<(sameCar?'1':'0')<<(sameRow?'1':'0')<<(sameSide?'1':'0')<<(adjacent?'1':'0')<<endl; 
return 0;
}
