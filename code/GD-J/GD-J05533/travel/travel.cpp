#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool yice(string a,string b){
	if(a[2]=='A'&&(b[2]=='B'||b[2]=='C')) return 1;
	if(a[2]=='B'&&(b[2]=='A'||b[2]=='C')) return 1;
	if(a[2]=='C'&&(b[2]=='B'||b[2]=='A')) return 1;
	if(a[2]=='D'&&b[2]=='E') return 1;
	if(a[2]=='E'&&b[2]=='D') return 1;
	return 0;
}//判断同一侧 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}//同一节车厢 
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}//同一排 
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&yice(s1,s2)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}//同一侧 
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&yice(s1,s2)&&abs(int(s1[2])-int(s2[2]))==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}//相邻 
	return 0;
}
