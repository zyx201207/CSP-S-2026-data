#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string t[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;	
	if(c1==c2){
		t[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			t[1]='1';
			if(s1[2]<='C'&&s2[2]<='C'){
				t[2]='1';
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
					t[3]='1';
				}
				else t[3]='0';
			}
			else if(s1[2]>'C'&&s2[2]>'C'){
			    t[2]='1';
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
					t[3]='1';
				}
				else t[3]='0';
			}
			else {
				t[2]='0';
				t[3]='0';
			}
		}
		else{
			t[1]='0';
			t[2]='0';
			t[3]='0';
		}
	}
	else{
		t[0]='0';
		t[1]='0';
		t[2]='0';
		t[3]='0';
	}
	for(int i=0;i<4;i++){
	    cout<<t[i];	
	}
	return 0; 
}
