#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	long long t1,t2,st1,st2;
	cin>>c1>>s1>>c2>>s2;
	if (s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		t1=1;
		if (s1[2]=='A'){
			st1=1;
		}
		else if (s1[2]=='B'){
			st1=2;
		}
		else{
			st1=3;
		}
	}
	else{
		t1=2;
		if (s1[2]=='D'){
			st1=4;
		}
		else{
			st1=5;
		}
	}
	if (s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		t2=1;
		if (s2[2]=='A'){
			st2=1;
		}
		else if (s2[2]=='B'){
			st2=2;
		}
		else{
			st2=3;
		}
	}
	else{
		t2=2;
		if (s2[2]=='D'){
			st2=4;
		}
		else{
			st2=5;
		}
	}
	if (c1==c2){
		cout<<"1";
		if (s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if (t1==t2){
				cout<<"1";
				if (max(st1,st2)-min(st1,st2)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	
}
