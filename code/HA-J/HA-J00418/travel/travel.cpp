#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool cmp1(string s1,string s2){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')return 1;
		else return 0;
	}
	else if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F')return 1;
		else return 0;
	}
}
bool cmp2(string s1,string s2){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(abs(s2[2]-s1[2])==1)return 1;
		else return 0;
	}
	else if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F')return 1;
		else return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
    	cout<<"1";
    	if(s1[0]==s2[0]&&s1[1]==s2[1]){
    		cout<<"1";
    		if(cmp1(s1,s2)){
    			cout<<"1";
    			if(cmp2(s1,s2))cout<<"1";
    			else cout<<"0";
			}
			else cout<<"00";
		}
    	else cout<<"000";
	}
    else cout<<"0000";
	cout<<endl;
	return 0;
}
