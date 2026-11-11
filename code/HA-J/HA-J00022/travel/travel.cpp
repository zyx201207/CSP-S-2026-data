#include<bits/stdc++.h>
using namespace std;

bool check1(string s1,string s2){
	if(s1=="A" || s1=="B" || s1=="C"){
		if(s2=="A" || s2=="B" || s2=="C"){
			return true;
		}
	}
	if(s1=="D" || s1=="F"){
		if(s2=="D" || s2=="F"){
			return true;
		}
	}
	return false;
}
bool check2(string s1,string s2){
	if(s1=="A" && s2=="B"){
		return true;
	}
	if(s1=="B" && s2=="A"){
		return true;
	}
	if(s1=="B" && s2=="C"){
		return true;
	}
	if(s1=="C" && s2=="B"){
		return true;
	}
	if(s1=="D" && s2=="F"){
		return true;
	}
	if(s1=="F" && s2=="D"){
		return true;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int ss1,ss2;
	cin>>c1>>ss1>>s1>>c2>>ss2>>s2;
	if(c1==c2){
		cout<<"1";
		if(ss1==ss2){
			cout<<"1";
			if(check1(s1,s2)){
				cout<<"1";
				if(check2(s1,s2)){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
