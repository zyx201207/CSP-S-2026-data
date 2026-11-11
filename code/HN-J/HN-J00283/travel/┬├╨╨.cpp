#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    getline(cin,c1);
    getline(cin,s1);
    getline(cin,c2);
    getline(cin,s2);
    if(c1!=s1){
    	cout<<"0000";
    	return 0;
	}else{
		cout<<"1";
		if(c2[1]==s2[1] && c2[2]==s2[2]){
			cout<<"1";
			if(c2[3]!='C'  &&  s2[3]!='D'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
			    }
			}else if(c2[3]!='C'  &&  s2[3]!='D'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(c2[3]=='C' && s2[3]=='A' || s2[3]=='B'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(c2[3]=='A' && s2[3]=='C' || s2[3]=='B'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(c2[3]=='B' && s2[3]=='A' || s2[3]=='C'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(c2[3]=='B' && s2[3]=='C' || s2[3]=='A'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(c2[3]=='D' && s2[3]=='F'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(c2[3]=='F' && s2[3]=='D'){
				cout<<"1";
				if(c2[3]==s2[3]-1 || c2[3]-1==s2[3]){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}
}
