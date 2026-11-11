#include <bits/stdc++.h>
using namespace std;

int getrow(string s){
	int ans=0;
	ans+=s[1]-'0'+(s[0]-'0')*10;
	return ans;
}
int getside(string s){//0Îª×óÅÅABC 1ÎªÓÒÅÅDE 
	char c=s[2];
	if(c=='A' || c=='B' || c=='C') return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	bool ok=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	//Q1
	if(c1==c2) ok=1;
	if(!ok){
		cout<<"0000";
		return 0;
	}
	
	//Q2
	ok=0;
	int row1=getrow(s1),row2=getrow(s2);
	if(row1==row2) ok=1;
	if(!ok){
		cout<<"1000";
		return 0;
	}
	
	//Q3
	ok=0;
	bool side1=getside(s1),side2=getside(s2);
	int r1=getrow(s1),r2=getrow(s2);
	if(side1==side2) ok=1;
	if(!ok){
		cout<<"1100";
		return 0;
	}
	
	//Q4
	char k1=s1[2],k2=s2[2];
	int dst=abs(k1-k2);
	if(dst==1) ok=1;
	if(!ok){
		cout<<"1110";
	}
	else cout<<"1111";
	
	return 0;
}
