#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,w1,s2,w2;
	cin>>s1>>w1>>s2>>w2;
	if(s1==s2){
		cout<<"1";
		if(w1[0]==w2[0]&&w1[1]==w2[1]){
			cout<<"1";
			if(((w2[2]=='D'||w2[2]=='F')&&(w1[2]=='D'||w1[2]=='F'))||((w2[2]!='D'&&w2[2]!='F')&&(w1[2]!='D'&&w1[2]!='F'))){
				cout<<"1";
				if(((w2[2]=='D'||w2[2]=='F')&&(w1[2]=='D'||w1[2]=='F'))||(w1[2]-1==w2[2]||w1[2]+1==w2[2]))
					cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0; 
} 
