#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> syf;
string c1,s1,c2,s2;
void ans(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		syf.push_back(1);
		cout<<1;
	}
	else{
		return;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		syf.push_back(1);
				cout<<1;
	}
	else{
		return;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		syf.push_back(1);
				cout<<1;
	}
	else{
		return;
	}
	if(char(s1[2])==char(s2[2]+1)||char(s1[2])==char(s2[2]-1)){
		syf.push_back(1);
				cout<<1;
	}
	else{
		return;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ans();
	int w=syf.size();
	if(w<4){
		for(int i=0;i<4-w;i++){
			cout<<0;
		}
	}
	return 0;
}
