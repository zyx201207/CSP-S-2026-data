#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int check3(){
	if(s1[2]=='D' or s1[2]=='F'){
		if(s2[2]=='D' or s2[2]=='F'){
			return 1; 
		}else{
			return 0;
		}
	}
	if(s2[2]!='D' and s2[2]!='F'){
		return 1;
	}else{
		return 0;
	}
}
int check4(){
	if(s1[2]=='D' or s1[2]=='F')return 1;
	if(s1[2]=='A' and s2[2]=='B')return 1;
	if(s1[2]=='C' and s2[2]=='B')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			if(check3()){
				cout<<1;
				if(check4()){
					cout<<1;
				}else{
					cout<<0;
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
}
