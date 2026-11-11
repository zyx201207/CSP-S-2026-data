#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long m1,m2;
int main(){
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D') m1=4;
	else if(s1[2]=='F') m1=5;
	else m1=s1[2]-'A';
	if(s2[2]=='D') m2=4;
	else if(s2[2]=='F') m2=5;
	else m2=s2[2]-'A';
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<'1';
			if((m1>=0 and m1<=2) and (m2>=0 and m2<=2) or(m1>=4 and m1<=5) and (m2>=4 and m2<=5)){
				cout<<'1';
				if(s1[2]+1==s2[2] or s1[2]-1==s2[2]) cout<<'1';
				else cout<<'0';
			} 
			else cout<<"00";
			
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
